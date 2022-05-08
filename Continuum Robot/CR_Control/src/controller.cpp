#include <chrono>
#include <controller.h>
#include <ctime>
#include <exception>
#include <thread>

Controller::Controller(TDCRModelDVS *tdcr, CTCRModel *ctcr) {

  mp_TDCR = tdcr;
  mp_CTCR = ctcr;
}
// One stays the same. One moves and the other extentdss in the oipposting
// direction.

Controller::~Controller() {}

// This function implements a single control iteration for a three segment TDCR.
// It implements pose control, meaning it takes a target frame as an input and
// calculates a step in Q for the TDCR to approach this new frame (in terms of
// orientation and position). It then applies this step to the TDCR and updates
// its state for the next control iteration, while returning its new tip frame
// and shape.
//
// Inputs:
// T_target					4x4 matrix, specifying the
// target tip frame for the current control iteration T_sd. wdls_jac Boolean
// value, specifying if a damped (singularity robust) Jacobian should be
// utilized in the control iteration gain
// Double value, specifying the proportional gain of the controller
//
// Outputs:
// ee_frame					4x4 matrix, specifying the
// end-effector frame of the updated TDCR after the control iteration
// disk_frames 4x4(3*n+1) matrix, storing the disk frames of the updated TDCR
// after the control iteration
void Controller::execute_tdcr_control_iteration(Eigen::Matrix4d &ee_frame,
                                                Eigen::MatrixXd &disk_frames,
                                                Eigen::Matrix4d T_target,
                                                bool wdls_jac, double gain) {
  // Get current frame and configuration of TDCR
  Eigen::Matrix4d T_cur = mp_TDCR->get_ee_frame();
  Eigen::MatrixXd q_tar = mp_TDCR->get_current_config();
  Eigen::MatrixXd q_cur = mp_TDCR->get_current_config();

  // YOUR CODE GOES HERE
  int verbose = 1;
  int nCols = 4;
  int nRows = 4;
  double maxChange = 1e-4;

  // This waits till we get to the end effector position.
  bool changing = true;
  while (changing) {
    // Getting Body Twist
    Eigen::MatrixXd body_twist(6, 1);
    body_twist = calculate_desired_body_twist(T_target, T_cur);

    // Gaining Body Twist
    Eigen::MatrixXd twistGained(6, 1);
    twistGained.setZero();
    twistGained = body_twist * gain;

    // We use all 6 points.
    Eigen::MatrixXd jacobian(6, 6);
    jacobian.setZero();
    mp_TDCR->get_body_jacobian(jacobian, q_cur);

    // Determination of a singularity.
    double singularity = jacobian.determinant();
    if (singularity == 0) {
      std::cout << "Jacobian " << jacobian << std::endl;
      std::cout << "Singularity!!" << std::endl;
      wdls_jac = true;
    }

    // Inverse Jacobian
    Eigen::MatrixXd jacobianInverted(6, 6);
    Eigen::MatrixXd j(6, 6);
    jacobianInverted.setZero();
    j.setZero();
    j = jacobian;
    // std::cout << "WDLSJAC" << wdls_jac << std::endl;

    if (wdls_jac == true) {
      // td::cout << "Got Here!" << std::endl;
      double nps = 2.5;
      Eigen::MatrixXd w1(6, 6);
      w1.setZero();
      w1 = Eigen::Matrix3d::Identity(6, 6) * nps;
      jacobianInverted = (j.transpose() * j + w1).inverse() * j.transpose();
    } else {
      // std::cout << "Something -> " << j.transpose() * (j *
      // j.transpose()).inverse() << std::endl;
      jacobianInverted = j.transpose() * (j * j.transpose()).inverse();
    }

    // Change in Q Values
    Eigen::MatrixXd qChange(6, 1);
    qChange.setZero();
    qChange = jacobianInverted * twistGained;
    // std::cout << "Q Change -> " << qChange << std::endl;

    // New Q Values
    int nQ = 9;        // Number of Q values
    int nSegments = 3; // Number of segments
    int nTendons = 3;  // Number of tendons per segement
    int nJ2S = 2;      // Number of columns in the jacobian for each segment

    Eigen::MatrixXd qNew(nQ, 1);
    qNew.setZero();
    qNew = q_tar;

    int k = 0;
    for (int i = 0; i < nSegments; i++) {
      for (int j = 0; j < nJ2S; j++) {
        int plusTendon = i * nSegments + j;
        int minuxTendon = i * nSegments + 2;
        qNew(plusTendon) += qChange(k);
        qNew(minuxTendon) -= qChange(k);
      }
    }

    // Doing Forward Kinematics
    std::cout << "Current End Effector! \n" << T_cur << std::endl;
    std::cout << "Goal End Effector! \n" << T_target << std::endl;
    mp_TDCR->forward_kinematics(ee_frame, disk_frames, qNew);
    T_cur = mp_TDCR->get_ee_frame();
    q_tar = mp_TDCR->get_current_config();
    break;

    // Checking if we need to change or not.
    // changing = false;
    // for (int r = 0; r < nRows; r++) {
    //  for (int c = 0; c < nCols; c++) {
    //    double targetEE = T_target(r, c);
    //    double currentEE = T_cur(r, c);
    //    if (std::abs(targetEE - currentEE) > maxChange) {
    //      changing = true;
    //    }
    //  }
    //}
    // changing = false;
    // if (changing == false) {
    //  if (verbose >= 2) {
    //    std::cout << "Target Frame -> " << T_target << std::endl;
    //    std::cout << "Current Frame -> " << T_cur << std::endl;
    //  }
    //  if (verbose >= 1) {
    //    std::cout << "Finished a movement for the TDCR " << std::endl;
    //  }
    //}
  }
}

/**
 * @brief This function implements a single control iteration for a three
 tube CTCR. It implements position control, meaning it takes a target frame
 as an input and calculates a step in Q for the CTCR to approach the new
 position of this frame (Note: ignoring orientation!). It then applies this
 step to the CTCR and updates its state for the next control iteration,
 while returning its new tip frame and shape.
 *
        OUTPUTS
 * @param ee_frame 4x4 matrix, specifying the end-effector frame of the
 updated CTCR after the control iteration
 * @param backbone_centerline 4x4(m*n+1) dimensional matrix storing n frames
 for each of the m subsegments of the updated CTCR after the control
 iteration
 * @param tube_ind Vector with m entries, specifying the outermost tube for
 each of the m subsegments of the updated CTCR after the control iteration

        INPUTS
 * @param T_target 4x4 matrix, specifying the target tip frame for the
 current control iteration T_sd.
 * @param wdls_jac Boolean value, specifying if a damped (singularity
 robust) Jacobian should be utilized in the control iteration
 * @param gain Double value, specifying the proportional gain of the
 controller
 */
void Controller::execute_ctcr_control_iteration(
    Eigen::Matrix4d &ee_frame, Eigen::MatrixXd &backbone_centerline,
    std::vector<int> &tube_ind, Eigen::Matrix4d T_target, bool wdls_jac,
    double gain) {
  // std::cout << "HELLO WORLD" << std::endl;
  // Get current frame and configuration of CTCR

  // mp_CTCR->forward_kinematics(ee_frame, backbone_centerline, tube_ind,
  // q_cur);

  /*
  WHAT TO DO

  1. Calculate body twist
  2. Reduce twist to only translation
  3. PRopertional Gain the twist
  4. Calculate body jacobian of CTCR in current
  5. Reduce Jacobian to last three rows only
  6. Caclulate a step in Q to update CTCR based on requested control mode
  7. If singularity robust jacboian is option is false
          use simple pseudoinverse
  8. If sinuglar roboust jacobia is optino is true
          considered a dampeed psudoinverse using w1 = diaddzg(0.001, 0.001,
  0.001, 1, 1, 1)
  9. Caclualte the new joint values for the CTCR
  10. Update the CTCR by calling its fkine with new joints vlaue
  11. Return the new end effector frame with robot backbone info to update the
  visualization
  */

  int verbose = 3;

  double maxChange = 1e-2;
  Eigen::MatrixXd qChange(6, 1);
  qChange << 1, 1, 1, 1, 1, 1;

  Eigen::MatrixXd q_cur = mp_CTCR->get_current_config();
  Eigen::Matrix4d T_cur = mp_CTCR->get_ee_frame();

  // Finding how much change is requried.
  Eigen::MatrixXd body_twist(6, 1);
  body_twist = calculate_desired_body_twist(T_target, T_cur);

  // Reduce Twist to only translation
  // Translation only requires the last three points.
  Eigen::MatrixXd twistTranslation(3, 1);
  twistTranslation = body_twist.block<3, 1>(3, 0);

  // Propertional gain the twist
  Eigen::MatrixXd twistGained(3, 1);
  twistGained = twistTranslation * gain;

  // Calculating the current Jacobian.
  Eigen::MatrixXd jacobianFull(6, 6);
  jacobianFull.setZero(6, 6);
  if (!mp_CTCR->get_body_jacobian(jacobianFull, q_cur)) {
    std::cout << "Body Jacobian is returning false!" << std::endl;
  }

  // Reduce the Jacobian to only translation.
  Eigen::MatrixXd jacobianTranslation(3, 6);
  jacobianTranslation = jacobianFull.block<3, 6>(3, 0);
  std::cout << "Jacobian Translation -> " << jacobianFull << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  // Find any singularities
  double singularity = jacobianFull.determinant(); // Singularity

  // Finding the inverted Jacobian
  Eigen::MatrixXd jacobianInverted; // The Jacobian
  jacobianInverted.setZero();
  {
    // If there is a singularity.
    if (singularity == 0) {
      wdls_jac = true;
    }
    // If WDLS is not selected
    if (wdls_jac == false) {
      Eigen::MatrixXd Jm = jacobianTranslation; // This is to save space. No
                                                // real need to do this.
      jacobianInverted = Jm.transpose() * (Jm * Jm.transpose()).inverse();
      // jacobianInverted = (Jm.transpose() * Jm).inverse() * Jm.transpose();
      // Something is wrong with this!!!
    }
    // If WDLS is selected
    else {
      Eigen::MatrixXd Jm = jacobianTranslation;
      Eigen::MatrixXd W1(6, 6); // The Diagonal Matrix
      W1.setZero();             // Setting all values to zero just in case
      W1.diagonal() << 0.001, 0.001, 0.001, 1, 1, 1;

      jacobianInverted = (Jm.transpose() * Jm + W1).inverse() * Jm.transpose();
      // jacobianInverted = (Jm.transpose() * Jm + W1).inverse() *
      // Jm.transpose();
    }
  }

  // Creating new Q diriviatives
  // qChange(6, 1);
  qChange.setZero();
  qChange = jacobianInverted * twistGained;

  // Take time integral of Q.
  Eigen::MatrixXd qNew = q_cur + qChange;

  // Update Valkues
  if (!mp_CTCR->forward_kinematics(ee_frame, backbone_centerline, tube_ind,
                                   qNew)) {
    std::cout << "Something broke and I do not know why ! " << std::endl;
  }

  // Feedback
  if (verbose >= 1) {
    std::cout << "Q  Values -> " << qNew << std::endl;
    std::cout << "original  Values -> " << q_cur << std::endl;
    std::cout << "Q Changes -> " << qChange << std::endl;
    std::cout << "Target Frame -> " << T_target << std::endl;
    std::cout << "End Frame -> " << ee_frame << std::endl;
  }

  // std::this_thread::sleep_for(std::chrono::nanoseconds(10));

  //std::this_thread::sleep_until(std::chrono::system_clock::now() +
  //                              std::chrono::seconds(1));
}
