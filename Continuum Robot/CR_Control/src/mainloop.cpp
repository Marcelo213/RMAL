#include <mainloop.h>
#include <iostream>
#include <time.h>
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
// %EndTag(MSG_HEADER)%

#include <sstream>

#include "common.h"
#include <unistd.h>

MainLoop::MainLoop(Visualizer *vis, TDCRModelDVS *tdcr, double timestep, int area) {
  m_timestep = timestep;
  mp_Vis = vis;
  mp_TDCR = tdcr;
  m_loopCount = 0;
  m_area = area;
  m_control_loop_active = false;
  homing = false;
  
  int index = 0;
  int dxl_comm_result = COMM_TX_FAIL;             // Communication result
  int dxl_goal_position[2] = {MINIMUM_POSITION_LIMIT, MAXIMUM_POSITION_LIMIT};         // Goal position
  uint8_t dxl_error = 0;
  int32_t dxl_present_position = 0;  // Read 4 byte Position data

  // Open port#include <iostream>
#include <fstream>
  portHandler->openPort();
  portHandler->setBaudRate(BAUDRATE);
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, 0, ADDR_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, 1, ADDR_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  
  
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, 0, ADDR_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  if (dxl_comm_result == COMM_SUCCESS) {
    printf("Succeeded enabling DYNAMIXEL Torque. 1\n");
  }

   dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, 1, ADDR_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  if (dxl_comm_result == COMM_SUCCESS) {
    printf("Succeeded enabling DYNAMIXEL Torque. 2\n");
  }
  
  //MoveMotor1(4000);
  //MoveMotor2(4000);
 ///dxl_comm_result = packetHandler->read4ByteTxRx(portHandler, 0, ADDR_PRESENT_POSITION, (uint32_t*)&dxl_present_position, &dxl_error);
  //dxl_comm_result = packetHandler->read4ByteTxRx(portHandler, 1, ADDR_PRESENT_POSITION, (uint32_t*)&dxl_present_position, &dxl_error);
  //dxl_comm_result = packetHandler->write4ByteTxRx(portHandler, DXL_ID, ADDR_GOAL_POSITION, dxl_goal_position[index], &dxl_error);
  //dxl_comm_result = packetHandler->read4ByteTxRx(portHandler, DXL_ID, ADDR_PRESENT_POSITION, (uint32_t*)&dxl_present_position, &dxl_error);
  //dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_TORQUE_ENABLE, TORQUE_DISABLE, &dxl_error);
  //portHandler->closePort();

 std::vector<Eigen::Matrix4d> vispath;

  double q1P = 0;
  double q2P = 0;
  double q3P = 0;
  double q4P = 0;
  Eigen::MatrixXd d;
  Eigen::Matrix4d ee;
  Eigen::MatrixXd qN(2,1);
  qN << 0,0;

  int curStep =0;
  Eigen::Matrix4d pPos; //Previous position
  double diff = 1000;//1m
  // Make path

  
  
  dist = std::normal_distribution<double>(mean, stddev);

  double end = 2*3.14;
  int t_steps = 1000;  
  double l = 0.343;
  double r = 0.2;// * std::rand()/RAND_MAX;
  double n = 1;// * std::rand()/RAND_MAX;
  double pi2 = 2*M_PI;
  for (double t = 0; t <= 1; t += 0.005){
    qN(0,0) = 0.01*t*std::sin(n*t*pi2);// + dist(generator);
    qN(1,0) = 0.01*t*std::cos(n*t*pi2);// + dist(generator);
    mp_TDCR->forward_kinematics(ee, d, qN);
    
    //ee(0,3) = ee(0,3)*3 + dist(generator);
    //ee(1,3) = ee(1,3)*3 + dist(generator);
    //ee(2,3) = ee(2,3) + dist(generator);
    
    m_targets.push_back(ee);
    vispath.push_back(ee);
  }
  for (double t = 1; t >=0; t -= 0.005){
    qN(0,0) = 0.01*t*std::sin(n*t*pi2);
    qN(1,0) = 0.01*t*std::cos(n*t*pi2);
    mp_TDCR->forward_kinematics(ee, d, qN);
    m_targets.push_back(ee);
    vispath.push_back(ee);
  }


  qN(0,0) = 0.00;
  qN(1,0) = 0.00;
  mp_TDCR->forward_kinematics(ee, d, qN);
              
  Eigen::MatrixXd enew(3, 1);
  enew << 0, 0, 0;
  error_integrate = enew;

  myfile.open("ground.csv");

  // Draw Goal Path
  mp_Vis->drawPath(vispath);
}

MainLoop::~MainLoop() {}


void MainLoop::Execute(vtkObject *caller, unsigned long eventId, void *vtkNotUsed(callData)) {
  if (vtkCommand::TimerEvent == eventId) {

    std_msgs::String msg;
    std::stringstream ss;
    //ss << "X pose: " << orb_position[0];
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    //ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    //chatter_pub.publish(msg);
    //Eigen::MatrixXd previousError;
    //previousError << 0, 0,0;

    ros::spinOnce();

    m_loopCount = m_loopCount + 1;

    //MoveMotor1(ConvertQM(q(0,0)));
    //MoveMotor2(ConvertQM(q(1,0)));
    
    Eigen::Matrix4d ee_frame;
    Eigen::MatrixXd disk_frames;
    Eigen::MatrixXd backbone_centerline;
    double _P  = 0.05;
    double _I  = 0;
    Eigen::MatrixXd q(2,1);
    //q << 0,0; 
    //mp_TDCR->forward_kinematics(ee_frame, disk_frames, q);
    // mp_Vis->updateTDCR(disk_frames);


    // TDCR Controller
    if (m_control_loop_active ) {
      //for (int i = 0; i<1; i++)
      //{
      //m_control_loop_active = false;


      if(m_loopCount >= m_targets.size() - 1){
          Eigen::MatrixXd qq(2,1);
          qq << 0, 0;
          mp_TDCR->forward_kinematics(ee_frame, disk_frames, qq);
          m_control_loop_active = false;

      }
      if(m_loopCount == 390) {
          myfile.close();
          m_control_loop_active = false;
          //homing = true;
      }
      std::cout << "Loop count: " << int(m_loopCount) << std::endl;
      Eigen::Matrix4d target = m_targets.at(m_loopCount); //600
      Eigen::MatrixXd qCur = mp_TDCR->get_current_config();
      Eigen::Matrix4d tCur2 = mp_TDCR->get_ee_frame();
      
      Eigen::Matrix4d tCur = Eigen::MatrixXd::Identity(4,4);

      tCur(0,3) = tCur2(0,3) + dist(generator);
      tCur(1,3) = tCur2(1,3) + dist(generator);
      tCur(2,3) = tCur2(2,3) + dist(generator);

      myfile << ros::Time::now() << ",";
      myfile << tCur(0,3) << ',' << tCur(1,3) << ',' << tCur(2,3) << ',';
      myfile << tCur(0,0) << ',' << tCur(0,1) << ',' << tCur(0,2) << ',';
      myfile << tCur(1,0) << ',' << tCur(1,1) << ',' << tCur(1,2) << ',';
      myfile << tCur(2,0) << ',' << tCur(2,1) << ',' << tCur(2,2) << std::endl;

      if (homing == true) {
        target = m_targets.at(5);
        //tCur(0,3) = orb_position[0] - orb_origin[0];
        //tCur(1,3) = orb_position[1] - orb_origin[1];
        //tCur(2,3) = 0.343 + (orb_position[2] - orb_origin[2]);
        //target(2,3) = 0.343;
        ROS_INFO("Pose Recieved: [%f]   [%f]    [%f]", tCur(0,3), tCur(1,3), tCur(2,3));
      }
      

      Eigen::MatrixXd twist = calculate_desired_body_twist(target, tCur);
      Eigen::MatrixXd tP = twist.block<3,1>(3,0);
      //Eigen::MatrixXd tP = Eigen::MatrixXd::Identity(4,4);
      // tP(0,3) = target(0,3) - tCur(0,3);
      //tP(1,3) = target(1,3) - tCur(1,3);
      //tP(2,3) = target(2,3) - tCur(2,3);

      error_integrate += tP;

      Eigen::MatrixXd Xe(3, 1);
      Xe = tP*_P + error_integrate*_I;
      //std::cout << "ERROR INTEGRATION:" << error_integrate << std::endl;

      //for (int i = 0; i<3; i++){
      //  tP(i,0) = tP(i,0) * P;//* 1;
      //}
      Eigen::MatrixXd jacobian(6, 2);
      mp_TDCR->get_body_jacobian(jacobian, qCur);

      Eigen::MatrixXd jm = jacobian.block<3, 2>(3,0);
      //Eigen::MatrixXd jinv = jm.transpose() * (jm * jm.transpose()).inverse();
      Eigen::MatrixXd jinv = (jm.transpose() * jm).inverse() * jm.transpose();
        
      Eigen::MatrixXd qChange = jinv * Xe;
      //std::cout << "Target:" << target << std::endl;
      //std::cout << "Current:" << tCur << std::endl;

      // min and max change
      for(int i =0; i<2; i++){
          if(qChange(i,0) >=  0.001){
              qChange(i,0) = 0.001; 
          }
          if(qChange(i,0) <=  -0.001){
              qChange(i,0) = -0.001;
          }
      }

      //qChange(0,0) = 0.0001;
      //qChange(1,0) = 0.0001;

      Eigen::MatrixXd qNew = qCur + qChange;
      //std::cout << "Q NEW: "<< qNew << std::endl;
      //std::cout << qNew;

      MoveMotor1(ConvertQM(qNew(0,0)));
      MoveMotor2(ConvertQM(qNew(1,0)));
      mp_TDCR->forward_kinematics(ee_frame, disk_frames, qNew);
      mp_Vis->updateTDCR(disk_frames);
      //std::cout << ee_frame << std::endl << std::endl;
      double diff = rmsDiff(ee_frame, target);
      //std::cout << diff << std::endl;
      usleep(100000);

      //}
    }
    else {
      std::cout << "atsrtarstars" << std::endl;
      Eigen::MatrixXd q(2,1);
      q << 0.000, 0.000;
      mp_TDCR->forward_kinematics(ee_frame, disk_frames, q);
      std::cout << ee_frame << std::endl;
      MoveMotor1(ConvertQM(q(0,0)));
      MoveMotor2(ConvertQM(q(1,0)));
    }
    

    // Hand new data to visualizer in order to update the scene
    if (m_loopCount * m_timestep >= 0.02) // Update Visualizer with 50 Hz (ms)
    {
      mp_Vis->update();
    }

    // End time measurement
    // clock_t end = std::clock();
    // double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC * 1000;
    // std::cout << elapsed_msecs << std::endl;

  } 

  if (vtkCommand::KeyPressEvent == eventId) // React on user input for each particular assignment
  {
    vtkRenderWindowInteractor *iren = static_cast<vtkRenderWindowInteractor *>(caller);
    // Start Loop
    if (strcmp((iren->GetKeySym()), "a")) {
      orb_origin[0] = orb_position[0];
      orb_origin[1] = orb_position[1];
      orb_origin[2] = orb_position[2];

      std::cout << "Happened" << std::endl;
      m_control_loop_active = true;
      m_loopCount = 0;
    }
  }
}

void MainLoop::MoveMotor1(int position){
  uint8_t dxl_error = 0;
  int32_t dxl_present_position = 0;
  int dxl_comm_result = COMM_TX_FAIL;

  dxl_comm_result = packetHandler->write4ByteTxRx(portHandler, 0, ADDR_GOAL_POSITION, position+4092, &dxl_error);  
  if (dxl_comm_result == COMM_SUCCESS)
  {
    //std::cout << "wrote to motor 1" << std::endl;
  }

}
void MainLoop::MoveMotor2(int position){
  uint8_t dxl_error = 0;
  int32_t dxl_present_position = 0;
  int dxl_comm_result = COMM_TX_FAIL;

  dxl_comm_result = packetHandler->write4ByteTxRx(portHandler, 1, ADDR_GOAL_POSITION, position, &dxl_error);
  if (dxl_comm_result == COMM_SUCCESS)
  {
    //std::cout << "wrote to motor 2" << std::endl;
  }
}

int MainLoop::ConvertQM(double q){
  double rad = (q*1000)/(8.5/2);
  double deg = rad/0.01745;
  int x = deg*(4092/360);
  if(x > 4000){
    x = 4000;
  }else if (x < -4000){
    x = -4000;
  }
  return x;
}
