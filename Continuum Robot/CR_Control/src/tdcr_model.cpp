#include <tdcr_model.h>

TDCRModel::TDCRModel(std::array<double, 3> length, int disks_per_seg,
                     std::array<double, 3> pradius_disks,
                     Eigen::Matrix4d base_frame) {

  m_length[0] = length[0];
  m_length[1] = length[1];
  m_length[2] = length[2];
  m_disks_per_seg = disks_per_seg;
  m_pradius_disks[0] = pradius_disks[0];
  m_pradius_disks[1] = pradius_disks[1];
  m_pradius_disks[2] = pradius_disks[2];
  m_base_frame = base_frame;

  m_current_config.resize(9, 1);
  m_current_config.setZero();
}

TDCRModel::~TDCRModel() {}

// This function should implement the forward kinematics of a tendon driven
// continuum robot (i.e. mapping tendon lengths changes in joint space to the
// robot's end-effector and disk frames) Inputs: q
// 9x1 matrix/vector holding the tendon displacement (changes in tendon lengths)
// for each tendon.
//							The first three tendons
// belong to
// segment one etc (3 Tendons per 3 Segments).
// A negative value indicates that the tendon is shortened (i.e. pulled).
//
// Outputs:
// ee_frame					4x4 matrix storing the
// end-effector frame resulting from the actuation q. disk_frames 4x4(3*n+1)
// dimensional matrix storing the frames for each of the n disks for each
// segment.
//							The leftmost 4x4 block
// should store the initial base/disk frame of the robot.
// boolean return value		True if kinematics have been calculated
// successfully, false if not.
//							Also return false, if
// the tendon length constraints are invalidated (the sum of tendon length
// changes in
// each segment has to equal zero).
bool TDCRModel::forward_kinematics(Eigen::Matrix4d &ee_frame,
                                   Eigen::MatrixXd &disk_frames,
                                   Eigen::MatrixXd q) {
  /*
  READ ME

  I use the value DEBUGGING to determining what is happening in the code.
  If you wish to visual the code feel free to use it.
  If you wish to simply see the results keep DEBUGGING as false.

  A tolerance value of 1.0e-10 is used. This value would realistically be higher
  For the sake of this assignment is it listed as such.

  The code is split into three main sections.
  Section 1.
          Determining if the tendons are suitable for use
          q1+q2+q3 == 0
  Section 2.
          Finding phi and kappa
  Section 3.
          Determining forward kinematics
  */

  // Predeterminined Variables
  int const nSegments = 3;      // Total number of segements
  int const nTendons = 9;       // Total number of tendons
  int const nST = 3;            // Tendons per segement
  bool const DEBUGGING = false; // If I want debugging info
  double const beta = 2 * M_PI / 3;

  Eigen::MatrixXd phi(1, nSegments);
  phi.setZero();
  Eigen::MatrixXd kappa(1, nSegments);
  kappa.setZero();
  Eigen::MatrixXd mout(4, 4);
  mout = Eigen::MatrixXd::Identity(4, 4);

  double summation = 0;
  double tolerance = 1.0e-10; // A very small number. close enough to zero.

  // Section 1
  // Detection of incorrect tendon lengths given.
  for (int i = 0; i < nSegments; i++) {
    double t1 = q(nST * i);     // 0, 3, 6
    double t2 = q(nST * i + 1); // 1, 4, 7
    double t3 = q(nST * i + 2); // 2, 5, 8
    if (abs(t1 + t2 + t3) > tolerance) {
      std::cout << "Error -> " << (t1 + t2 + t3) << std::endl;
      std::cout << "Q Values -> " << q << std::endl;
      std::cout << "The summation of the tendons was not equal to zero"
                << std::endl;
      std::cout << "The simulation was cancelled" << std::endl;
      return false;
    }
  }

  // Section 2
  // Finding kappa and phi.
  for (int i = 0; i < nSegments; i++) {
    // Getting the tendons
    double t1 = q(nST * i);     // 0, 3, 6
    double t2 = q(nST * i + 1); // 1, 4, 7
    double t3 = q(nST * i + 2); // 2, 5, 8

    // If T1=T2=0 then T3 must also be equal to zero.
    if (t1 == t2) {
      if (t1 == 0) {
        phi(i) = 0;
        kappa(i) = 0;
        continue; // No point doing the rest of this
      }
    }

    // Find phi.
    phi(i) = atan2(-t1 * cos(beta) + t2, -t1 * sin(beta));

    // phii and Displaceement
    Eigen::MatrixXd phii(1, nST);
    Eigen::MatrixXd displacements(1, nST);
    phii.setZero();
    displacements.setZero();
    for (int j = 0; j < nST; j++) {
      phii(j) = (j - 1) * beta - phi(i);
      displacements(j) = (m_pradius_disks[i] * cos(phii(j)));
    }

    // Finding Kappa. I do not know why but this does some strange stuff.
    // Could not figure out the base problem. This is a work around that seems
    // to work for some reason.
    double k1 = -t1 / (displacements(0) * m_length[i]);
    double k2 = -t2 / (displacements(1) * m_length[i]);
    double k3 = -t3 / (displacements(2) * m_length[i]);
    double t[3] = {t1, t2, t3};
    double minimum = *std::min_element(std::begin(t), std::end(t));
    if ((k1 > 0) && (t1 < 0)) {
      if (t1 == minimum) {
        kappa(i) = k1;
      }
    } else if ((k2 > 0) && (t2 < 0)) {
      if (t2 == minimum) {
        kappa(i) = k2;
      }
    } else if ((k3 > 0) && (t3 < 0)) {
      if (t3 == minimum) {
        kappa(i) = k3;
      }
    } else {
      double v[3] = {k1, k2, k3};
      kappa(i) = *std::max_element(std::begin(v), std::end(v));
    }
    // std::cout << "Kappa -> " << kappa(i) << std::endl;
  }

  // Section 3
  // Homogenous transformation
  // Conversion between vector a eigen
  {
    std::vector<double> _k{};
    std::vector<double> _l{};
    std::vector<double> _p{};
    for (int i = 0; i < nSegments; i++) {
      _k.push_back(kappa(i));
      _l.push_back(m_length[i]);
      //_p.push_back(phi(0));
      _p.push_back(phi(i));
    }
    ee_frame = Eigen::MatrixXd::Identity(
        4, 4); // This sets the size to the idenity matrix too.
    disk_frames = arc_to_x(ee_frame, _k, _l, _p, m_disks_per_seg, false);

    ee_frame.col(0) = disk_frames.col(disk_frames.cols() - 4);
    ee_frame.col(1) = disk_frames.col(disk_frames.cols() - 3);
    ee_frame.col(2) = disk_frames.col(disk_frames.cols() - 2);
    ee_frame.col(3) = disk_frames.col(disk_frames.cols() - 1);
  }

  // Setting the member variables accordingly
  m_ee_frame = ee_frame;
  m_disk_frames = disk_frames;
  m_current_config = q;

  return true;
}

// This function should calculate and return the body Jacobian of a tendon
// driven continuum robot using a simple finite differences approach Inputs: q
// 9x1 matrix/vector holding the tendon displacement (changes in tendon lengths)
// for each tendon.
//							The first three tendons
// belong to segment one etc (3 Tendons per 3 Segments).
// J						6x6 body Jacobian matrix,
// relating joint space velocities with end-effector twist (beware the tendon
// constraints are manually resolved to reduce Q to six dimensions, representing
// the robot's DoF)
//							The first three rows
// correspond to the rotational part of a twist, while the last three rows
// correspond to the
// translational part
//
// Outputs:
// boolean return value		Return false, if if the tendon length
// constraints are invalidated.
//							Return true otherwise
//(and proceed to calculate and return J).
/**
 * @brief
 *
 * @param J
 * @param q
 * @return true
 * @return false
 */
bool TDCRModel::get_body_jacobian(Eigen::MatrixXd &J, Eigen::MatrixXd q) {
  // Resize J and set to zero
  J.setZero(6, 6);

  // Evaluate at current configuration q
  Eigen::Matrix4d init_ee_frame;
  Eigen::MatrixXd init_disk_frames;
  Eigen::MatrixXd init_q = q;

  if (!forward_kinematics(init_ee_frame, init_disk_frames, q)) {
    for (int i = 0; i < 10; i++) {

      std::cout << "Failure!" << std::endl;
    }
    // Return false if joint value constraints are not met
    return false;
  }

  // Calculate the Body Jacobian using Finite Differences here (YOUR CODE GOES
  double h = 1e-4; // H nubmer
  int verbose = 1;

  int nQ = 9;        // Number of Q values
  int nSegments = 3; // Number of segments
  int nTendons = 3;  // Number of tendons per segement
  int nJ2S = 2;      // Number of columns in the jacobian for each segment
  for (int i = 0; i < nSegments; i++) {
    for (int j = 0; j < nJ2S; j++) {
      Eigen::Matrix4d eeNew;
      Eigen::MatrixXd diskNew;
      Eigen::MatrixXd qNew(6, 1);
      eeNew.setZero();
      diskNew.setZero(4, 4);
      qNew.setZero();
      qNew = q;

      // TDCR have their tendons in pairs.
      // Plus is the Q value that we use for our Jacobian Column.
      // Minus is the Q value that compensates for the plus Q.
      int plusTendon = i * nSegments + j;
      int minuxTendon = i * nSegments + 2;
      // Updating the value.
      qNew(plusTendon) = q(plusTendon) + h;
      qNew(minuxTendon) = q(minuxTendon) - h;

      // Do forward Kinematics
      if (!forward_kinematics(eeNew, diskNew, qNew)) {
        // Return false if joint value constraints are not met
        for (int i = 0; i < 10; i++) {
          std::cout << "Failure!2" << std::endl;
        }
        return false;
      }

      // Body Twist
      Eigen::MatrixXd body_twist =
          calculate_desired_body_twist(eeNew, init_ee_frame);

      // Adding to the Jacobian
      J.col(i * nJ2S + j) = body_twist.col(0) / h;

      // Feedback
      if (verbose >= 3) {
        std::cout << "Jacobian Column -> " << (i * nJ2S + j) << std::endl;
        std::cout << "Plus Tendon Point -> " << plusTendon << std::endl;
        std::cout << "Minus Tendon Point -> " << plusTendon << std::endl;
        std::cout << "Q Values -> " << qNew << std::endl;
        std::cout << "Jacobian Column Values -> " << J.col(i * nJ2S + j)
                  << std::endl;
      }
    }
  }

  if (verbose >= 2) {
    std::cout << std::endl;
    std::cout << "Jacobian (TDCR Jacobian) " << J << std::endl;
    std::cout << std::endl;
  }
  // HERE)
  // Setting the member variables accordingly
  m_ee_frame = init_ee_frame;
  m_disk_frames = init_disk_frames;
  m_current_config = init_q;

  return true;
}

Eigen::MatrixXd TDCRModel::get_current_config() { return m_current_config; }

Eigen::Matrix4d TDCRModel::get_ee_frame() { return m_ee_frame; }

Eigen::MatrixXd TDCRModel::get_disk_frames() { return m_disk_frames; }

Eigen::Matrix4d TDCRModel::get_base_frame() { return m_base_frame; }
