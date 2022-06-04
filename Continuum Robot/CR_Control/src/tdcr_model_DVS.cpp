#include <tdcr_model_DVS.h>

TDCRModelDVS::TDCRModelDVS(std::array<double, 1> length, int disks_per_seg,
                     std::array<double, 1> pradius_disks,
                     Eigen::Matrix4d base_frame) {

  m_length[0] = length[0];
  //m_length[1] = length[1];
  m_disks_per_seg = disks_per_seg;
  m_pradius_disks[0] = pradius_disks[0];
  //m_pradius_disks[1] = pradius_disks[1];
  m_base_frame = base_frame;

  m_current_config.resize(2, 1);
  m_current_config.setZero();
}

TDCRModelDVS::~TDCRModelDVS() {}

int TDCRModelDVS::getQ(){
    return m_nQ;
}   

// This function should implement the forward kinematics of a tendon driven
// continuum robot (i.e. mapping tendon lengths changes in joint space to the
// robot's end-effector and disk frames) Inputs: q
// 9x1 matrix/vector holding the tendon displacement (changes in tendon lengths)
// for each tendon.
// 
// The first three tendons belong to
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
bool TDCRModelDVS::forward_kinematics(Eigen::Matrix4d &ee_frame,
                                   Eigen::MatrixXd &disk_frames,
                                   Eigen::MatrixXd q) {
  double const beta = 2 * M_PI / 3;

  Eigen::MatrixXd mout(4, 4);
  std::vector<double> kappa{};
  std::vector<double> length{};
  std::vector<double> phi{};


  mout = Eigen::MatrixXd::Identity(4, 4);

  double summation = 0;
  double tolerance = 1.0e-10; // A very small number. close enough to zero.

  double l = 0.343;
  double r = (0.0375/2);
  double qx = q(0);
  double qy = q(1);

 // double qx2 = q(2);
  //double qy2 = q(3);

  
  double kx = qx/(l*r);
  double ky = qy/(l*r);
  //double kx2 = qx2/(l*r);
  //double ky2 = qy2/(l*r);


  double k1 = std::sqrt(kx*kx + ky*ky);
  //double k2 = std::sqrt(kx2*kx2 + ky2*ky2);

  double p1 = std::atan2(ky, kx);
  //double p2 = std::atan2(ky2, kx2);

  //std::cout << k1 << std::endl;
  //std::cout << k2 << std::endl;
  kappa.push_back(k1);
  //kappa.push_back(k2);
  phi.push_back(p1);
  //phi.push_back(p2);
  length.push_back(l);
  //length.push_back(0.001);


  // Homogenous transformation
  ee_frame = Eigen::MatrixXd::Identity(4, 4); 
  disk_frames = arc_to_x(ee_frame, kappa, length, phi, m_disks_per_seg, false);

  ee_frame.col(0) = disk_frames.col(disk_frames.cols() - 4);
  ee_frame.col(1) = disk_frames.col(disk_frames.cols() - 3);
  ee_frame.col(2) = disk_frames.col(disk_frames.cols() - 2);
  ee_frame.col(3) = disk_frames.col(disk_frames.cols() - 1);

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
bool TDCRModelDVS::get_body_jacobian(Eigen::MatrixXd &J, Eigen::MatrixXd q) {
  // Resize J and set to zero
  //J.setZero(6, 4);


  Eigen::MatrixXd jac(6, 2);
  jac.setZero();

  // Evaluate at current configuration q
  Eigen::Matrix4d init_ee_frame;
  Eigen::MatrixXd init_disk_frames;
  Eigen::MatrixXd init_q = q;

  forward_kinematics(init_ee_frame, init_disk_frames, q);

  // Calculate the Body Jacobian using Finite Differences 
  double h = 1e-4; // H nubmer

  for (int i = 0; i < 2; i++) {

    Eigen::Matrix4d eeNew;
    Eigen::MatrixXd diskNew;
    Eigen::MatrixXd qNew = init_q;
  
    qNew(i,0) = q(i, 0) + h ;
    forward_kinematics(eeNew, diskNew, qNew);

    // Body Twist
    Eigen::MatrixXd body_twist = calculate_desired_body_twist(eeNew, init_ee_frame);

    // Adding to the Jacobian
    J(0,i) = body_twist(0,0)/h;
    J(1,i) = body_twist(1,0)/h;
    J(2,i) = body_twist(2,0)/h;
    J(3,i) = body_twist(3,0)/h;
    J(4,i) = body_twist(4,0)/h;
    J(5,i) = body_twist(5,0)/h;
  }
  m_ee_frame = init_ee_frame;
  m_disk_frames = init_disk_frames;
  m_current_config = init_q;

  return true;
}

Eigen::MatrixXd TDCRModelDVS::get_current_config() { return m_current_config; }

Eigen::Matrix4d TDCRModelDVS::get_ee_frame() { return m_ee_frame; }

Eigen::MatrixXd TDCRModelDVS::get_disk_frames() { return m_disk_frames; }

Eigen::Matrix4d TDCRModelDVS::get_base_frame() { return m_base_frame; }

