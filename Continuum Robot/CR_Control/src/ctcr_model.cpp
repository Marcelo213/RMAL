#include <cmath>
#include <ctcr_model.h>

/*
      _                                 _      _
  ___| |_ ___ _ __  _ __ ___   ___   __| | ___| |  ___ _ __  _ __
 / __| __/ __| '__|| '_ ` _ \ / _ \ / _` |/ _ \ | / __| '_ \| '_ \
| (__| || (__| |   | | | | | | (_) | (_| |  __/ || (__| |_) | |_) |
 \___|\__\___|_|___|_| |_| |_|\___/ \__,_|\___|_(_)___| .__/| .__/
              |_____|                                 |_|   |_|

*/

CTCRModel::CTCRModel(std::array<double, 3> length, std::array<double, 3> ro,
                     std::array<double, 3> ri,
                     std::array<double, 3> straight_length,
                     std::array<double, 3> curvature, double youngs_modulus,
                     int pts_per_seg, Eigen::Matrix4d base_frame) {

  // std::cout << length[0] << std::endl;
  // std::cout << length[1] << std::endl;
  // std::cout << length[2] << std::endl;
  m_length[0] = length[0];
  m_length[1] = length[1];
  m_length[2] = length[2];

  m_ro[0] = ro[0];
  m_ro[1] = ro[1];
  m_ro[2] = ro[2];

  m_ri[0] = ri[0];
  m_ri[1] = ri[1];
  m_ri[2] = ri[2];

  m_straight_length[0] = straight_length[0];
  m_straight_length[1] = straight_length[1];
  m_straight_length[2] = straight_length[2];

  m_curvature[0] = curvature[0];
  m_curvature[1] = curvature[1];
  m_curvature[2] = curvature[2];

  m_youngs_modulus = youngs_modulus;
  m_points_per_seg = pts_per_seg;
  m_base_frame = base_frame;

  m_current_config.resize(6, 1);
  m_current_config.setZero();
}

CTCRModel::~CTCRModel() {}

// This function should implement the forward kinematics of a concnetric tube
// continuum robot (i.e. mapping tube rotations and translations in joint space
// to the robot's end-effector and shape) Inputs q
// 6x1 matrix/vector holding actuation values.
//							The first three entries
// are each tube's rotation, while the last three are the tube's translations.
//
// Outputs:
// ee_frame					4x4 matrix storing the
// end-effector frame resulting from the actuation q. disk_frames 4x4(m*n+1)
// dimensional matrix storing n frames for each of the m subsegments of the
// CTCR.
//							The leftmost 4x4 block
// should store the initial base/disk frame of the robot.
// tube_ind					Vector with m entries,
// specifying the outermost tube for each of the m subsegments. boolean return
// value True if kinematics have been calculated successfully, false if not.
//							Also return false, if
// the joints limits and inequality constraints are invalidated.
bool CTCRModel::forward_kinematics(Eigen::Matrix4d &ee_frame,
                                   Eigen::MatrixXd &backbone_centerline,
                                   std::vector<int> &tube_ind,
                                   Eigen::MatrixXd q) {

  // TODO LIST
  // FIND LENGTH AS YOU GO ON
  // FIND GREATEST TUBE OUTSIDE
  //
  // Verify all values
  // ALpha beta detection
  // EI Values (yes)
  // Check detection
  // Length detection
  // KX, Ky values
  // Kappa values
  // Phi values

  double global_phi = 0;

  bool const DEBUGGING = false;
  const int nTubes = 3;
  int nSegments = 0;
  std::vector<double> alphas{};
  std::vector<double> betas{};
  std::vector<double> straightEnds{};
  std::vector<double> curvedEnds{};
  std::vector<double> positions{};
  std::vector<double> eiValues{};
  std::vector<double> kappas{};
  std::vector<double> lengths{};
  std::vector<double> phis{};

  if (DEBUGGING) {
    std::cout << "\n\n #### DATA VERIFICATION #### \n\n";
  }
  // Seperating alphas and betas.
  for (int i = 0; i < nTubes; i++) {
    alphas.push_back(q(i));
    betas.push_back(q(i + nTubes));
  }
  if (DEBUGGING) {
    // Alphas
    std::cout << "Alpha values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << alphas.at(i) << " ";
    }
    std::cout << std::endl;
    // Betas
    std::cout << "Beta values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << betas.at(i) << " ";
    }
    std::cout << std::endl;
    // Lenghts
    std::cout << "Length values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_length[i] << " ";
    }
    std::cout << std::endl;
  }

  // Verifying beta sizes
  double previousB = 0;
  // Checking if each Beta is greater than the previous
  for (int i = nTubes - 1; i >= 0; i--) {
    // In the 10 examples all 10 work.
    if (betas.at(i) >= previousB) {
      if (DEBUGGING) {
        std::cout << "Current beta -> " << betas.at(i) << std::endl;
        std::cout << "previous beta -> " << previousB << std::endl;
        std::cout << "Failed" << std::endl;
      }
      return false;
    }
    previousB = betas.at(i);
  }
  if (DEBUGGING) {
    std::cout << "Passed check 1" << std::endl;
  }

  // Check 2
  // Determining if all lengths plus beta values are less than each other.
  double previousL = m_length[0];
  for (int i = 0; i < nTubes; i++) {
    if (betas.at(i) + m_length[i] >= previousL) {
      if (DEBUGGING) {
        std::cout << "Current length -> " << betas.at(i) + m_length[i]
                  << std::endl;
        std::cout << "previous Length -> " << previousL << std::endl;
        std::cout << "Failed" << std::endl;
      }
      return false;
    }
    previousL = betas.at(i) + m_length[i];
  }
  if (DEBUGGING) {
    std::cout << "Passed check 2" << std::endl;
  }

  // Finding I values
  for (int i = 0; i < nTubes; i++) {
    double I =
        m_youngs_modulus * (M_PI / 64) * (pow(m_ro[i], 4) - pow(m_ri[i], 4));
    eiValues.push_back(I);
  }
  if (DEBUGGING) {
    std::cout << "Youngs Modulus -> " << m_youngs_modulus << std::endl;
    std::cout << "M_PI -> " << M_PI << std::endl;
    // Outer diameter
    std::cout << "OD values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_ro[i] << " ";
    }
    std::cout << std::endl;
    // Inner diameter
    std::cout << "ID values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_ri[i] << " ";
    }
    std::cout << std::endl;
    // EI
    std::cout << "EI values - >";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_youngs_modulus * (M_PI / 64) *
                       (pow(m_ro[i], 4) - pow(m_ri[i], 4))
                << " ";
    }
    std::cout << std::endl;
  }

  // Determining points of intersts
  positions.push_back(0);
  for (int i = 0; i < nTubes; i++) {
    double straightLength = m_straight_length[i];
    double curvedLength = m_length[i] - m_straight_length[i];

    double straightEnd = betas.at(i) + m_straight_length[i];
    double curvedEnd = betas.at(i) + m_length[i];
    if (straightEnd < 0) {
      straightEnd = 0;
    }
    if (curvedEnd < 0) {
      curvedEnd = 0;
    }

    straightEnds.push_back(straightEnd);
    curvedEnds.push_back(curvedEnd);
    positions.push_back(straightEnd);
    positions.push_back(curvedEnd);
    std::sort(positions.begin(), positions.end());
    positions.erase(std::unique(positions.begin(), positions.end()),
                    positions.end());
    nSegments = positions.size();
  }
  if (DEBUGGING) {
    // Tube Lengths
    std::cout << "Tube Lengths -> ";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_length[i] << " ";
    }
    std::cout << std::endl;

    // Straight Tube Lengths
    std::cout << "Tube Straight Lengths -> ";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_straight_length[i] << " ";
    }
    std::cout << std::endl;

    // Curved Tube Lengths
    std::cout << "Tube Curved Lengths -> ";
    for (int i = 0; i < nTubes; i++) {
      std::cout << m_length[i] - m_straight_length[i] << " ";
    }
    std::cout << std::endl;

    // New Straight End;
    std::cout << "New Straight End -> ";
    for (int i = 0; i < nTubes; i++) {
      std::cout << betas.at(i) + m_straight_length[i] << " ";
    }
    std::cout << std::endl;

    // New Curved End;
    std::cout << "New Curved End -> ";
    for (int i = 0; i < nTubes; i++) {
      std::cout << betas.at(i) + m_length[i] << " ";
    }
    std::cout << std::endl;

    // nSegments
    std::cout << "Number of Points of interest -> " << nSegments << std::endl;

    // Segment Positions
    std::cout << "Points of interest Positions -> ";
    for (int i = 0; i < nSegments; i++) {
      std::cout << positions.at(i) << " ";
    }
    std::cout << std::endl;
  }

  // Coverting Q to Kappa,Phi,Length
  if (DEBUGGING) {
    std::cout << "\n\n #### PROCESSING #### \n\n";
  }
  for (int m = 0; m < nSegments - 1; m++) {
    double length = -1;
    double kappa = -1;
    double phi = -1;
    double curvatures[nTubes] = {};
    std::vector<int> tubesPresent = {};

    for (int i = 0; i < nTubes; i++) {
      curvatures[i] = -2;
    }

    // Finding Length
    length = positions.at(m + 1) - positions.at(m);

    double minimumTube = 0;
    double point = positions.at(m);

    // Finding Tubes Present.
    double nTubesPresent = 0;
    for (int i = 0; i < nTubes; i++) {
      if (curvedEnds.at(i) <= point) {
        curvatures[i] = -1;
      } else {
        nTubesPresent += 1;
        tubesPresent.push_back(i);
      }
    }

    // Determining if the tube present is straight or curved
    for (int i = 0; i < nTubesPresent; i++) {
      if (straightEnds.at(tubesPresent.at(i)) > point) {
        curvatures[tubesPresent.at(i)] = 0;
      } else {
        curvatures[tubesPresent.at(i)] = m_curvature[tubesPresent.at(i)];
      }
    }

    // Finding EI sum
    double eiSum = 0;
    for (int i = 0; i < nTubes; i++) {
      if (curvatures[i] != -1) {
        eiSum += eiValues.at(i);
      }
    }
    // Finding EIkcos(a), EIksin(a)
    double kx_ = 0;
    double ky_ = 0;
    for (int i = 0; i < nTubes; i++) {
      if (curvatures[i] != -1 && curvatures[i] != 0) {
        kx_ += eiValues.at(i) * m_curvature[i] * cos(alphas.at(i));
        ky_ += eiValues.at(i) * m_curvature[i] * sin(alphas.at(i));
      }
    }

    // Finding KX and Ky
    double kx = (1 / eiSum) * kx_;
    double ky = (1 / eiSum) * ky_;

    // Finding Kappa and Phi
    kappa = sqrt(pow(kx, 2) + pow(ky, 2));
    phi = atan2(ky, kx) - global_phi;
    global_phi = atan2(ky, kx);

    // Final Saves
    tube_ind.push_back(nTubesPresent);
    kappas.push_back(kappa);
    phis.push_back(phi);
    lengths.push_back(length);

    // Debugging
    if (DEBUGGING) {
      std::cout << "Number of tubes present -> " << nTubesPresent << std::endl;
      std::cout << "EI sum -> " << eiSum << std::endl;
      std::cout << "Kx part -> " << kx_ << std::endl;
      std::cout << "Ky part -> " << ky_ << std::endl;
      std::cout << "Kx -> " << kx << std::endl;
      std::cout << "Ky -> " << kx << std::endl;
      std::cout << "Kappa -> " << kappa << std::endl;
      std::cout << "Phi -> " << phi << std::endl;
      std::cout << "Length -> " << length << std::endl;
      std::cout << std::endl;
    }
  }
  if (DEBUGGING) {
    std::cout << "\n\n #### OUTPUT #### \n\n";
    std::cout << "Kappas -> ";
    for (int i = 0; i < positions.size() - 1; i++) {
      std::cout << kappas.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Phis -> ";
    for (int i = 0; i < positions.size() - 1; i++) {
      std::cout << phis.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Lengths -> ";
    for (int i = 0; i < positions.size() - 1; i++) {
      std::cout << lengths.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Outermost Tube -> ";
    for (int i = 0; i < positions.size() - 1; i++) {
      std::cout << tube_ind.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Base Frame -> ";
    std::cout << m_base_frame << std::endl;
    std::cout << std::endl;
  }

  // Converting to kinematics and getting the end effector frame.
  backbone_centerline =
      arc_to_x(m_base_frame, kappas, lengths, phis, m_points_per_seg, true);
  // WE SHOULD USE BISHOP =TRUE HERE. But its not working the way it should be.
  backbone_centerline =
      arc_to_x(m_base_frame, kappas, lengths, phis, m_points_per_seg, false);
  ee_frame.col(0) = backbone_centerline.col(backbone_centerline.cols() - 4);
  ee_frame.col(1) = backbone_centerline.col(backbone_centerline.cols() - 3);
  ee_frame.col(2) = backbone_centerline.col(backbone_centerline.cols() - 2);
  ee_frame.col(3) = backbone_centerline.col(backbone_centerline.cols() - 1);
  std::cout << "\n\n\n\n";

  // Setting the member variables accordingly
  m_ee_frame = ee_frame;
  m_backbone_centerline = backbone_centerline;
  m_current_config = q;

  return true;
}


bool CTCRModel::get_body_jacobian(Eigen::MatrixXd &J, Eigen::MatrixXd q) {
  // Resize J and set to zero
  J.setZero(6, 6);

  // Evaluate at current configuration q
  Eigen::Matrix4d init_ee_frame;
  Eigen::MatrixXd init_backbone_centerline;
  std::vector<int> tube_ind;
  Eigen::MatrixXd init_q = q;

  if (!forward_kinematics(init_ee_frame, init_backbone_centerline, tube_ind,
                          q)) {
    // Return false if joint value constraints are not met
    return false;
  }
  // YOUR CODE STARTS HERE
  int verbose = 3;
  // H value
  double h = 1e-4;

  // Creating Each column of the Jacobian
  for (int i = 0; i < q.rows(); i++) {
    Eigen::MatrixXd qNew = q;
    Eigen::Matrix4d eeNew;
    Eigen::MatrixXd centerlineNew;
    std::vector<int> tubeesNew;

    // Modifying Q Values
    qNew(i, 0) = q(i, 0) + h;

    // Setting Forward Kinematics to zero just in case
    eeNew.setZero();
    centerlineNew.setZero();

    // Do forward Kinematics
    if (!forward_kinematics(eeNew, centerlineNew, tubeesNew, qNew)) {
      return false;
    }

    // Getting Body twist or delta X
    //Eigen::MatrixXd body_twist = calculate_desired_body_twist(init_ee_frame, eeNew);
    Eigen::MatrixXd body_twist = calculate_desired_body_twist(eeNew, init_ee_frame);
    // Adding each deltaX to the jacobian
    J.col(i) = body_twist.col(0) / h;


    if(verbose >=3)
    {
      //std::cout << "Body twist\n" << body_twist << std::endl;
      std::cout << "Target Position" << init_ee_frame << std::endl;
      std::cout << "Current Position" << eeNew << std::endl;
      std::cout << "Original Q \n" << q << std::endl;
      std::cout << "Changed Q \n" << qNew << std::endl;
      std::cout << "Body twist\n" << body_twist << std::endl;
      std::cout << "Body over H \n" << body_twist/h << std::endl;
    }
  }

  // YOUR CODE ENDS HERE

  // Setting the member variables accordingly if q was valid
  m_ee_frame = init_ee_frame;
  m_backbone_centerline = init_backbone_centerline;
  m_current_config = init_q;

  return true;
}

Eigen::MatrixXd CTCRModel::get_current_config() { return m_current_config; }

Eigen::Matrix4d CTCRModel::get_ee_frame() { return m_ee_frame; }

Eigen::MatrixXd CTCRModel::get_backbone_centerline() {
  return m_backbone_centerline;
}

Eigen::Matrix4d CTCRModel::get_base_frame() { return m_base_frame; }
