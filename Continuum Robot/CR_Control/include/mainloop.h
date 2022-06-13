#pragma once

#define _USE_MATH_DEFINES

#include <visualizer.h>
#include <robot_independent.h>
#include <tdcr_model_DVS.h>
#include <controller.h>

//stl
#include <ctime>
#include <cmath>
#include <fstream>
#include <random>

//vtk
#include <vtkSmartPointer.h>
#include <vtkCommand.h>
#include <vtkRenderWindowInteractor.h>

//Eigen
#include <Eigen/Dense>

#if defined(__linux__) || defined(__APPLE__)
#include <fcntl.h>
#include <termios.h>
#define STDIN_FILENO 0
#elif defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "dynamixel_sdk.h"  // Uses DYNAMIXEL SDK library
#include "port_handler_linux.h"

/********* DYNAMIXEL Model definition *********
***** (Use only one definition at a time) *****/
#define X_SERIES
#if defined(X_SERIES) || defined(MX_SERIES)
  #define ADDR_TORQUE_ENABLE          64
  #define ADDR_GOAL_POSITION          116
  #define ADDR_PRESENT_POSITION       132
  #define MINIMUM_POSITION_LIMIT      0  // Refer to the Minimum Position Limit of product eManual
  #define MAXIMUM_POSITION_LIMIT      4095  // Refer to the Maximum Position Limit of product eManual
  #define BAUDRATE                    57600
#endif

#define PROTOCOL_VERSION  2.0
#define DXL_ID  1
#define DEVICENAME  "/dev/ttyUSB1" // Have to change this for windows OS *****
#define TORQUE_ENABLE                   1
#define TORQUE_DISABLE                  0
#define DXL_MOVING_STATUS_THRESHOLD     20  // DYNAMIXEL moving status threshold
#define ESC_ASCII_VALUE                 0x1b

// Class that implements the main simulation loop
class MainLoop : public vtkCommand
{
	private:
		Visualizer* mp_Vis;
		Controller* mp_Controller;
		TDCRModelDVS* mp_TDCR;
		
        double m_timestep;
		int m_area;
        double m_loopCount;
		int m_assignment;
		int m_counter;
		std::vector<Eigen::MatrixXd> m_configs;
		bool m_control_loop_active;

		bool homing;
		int m_control_scenario;
		Eigen::Matrix4d m_control_target_frame;
		std::vector<Eigen::Matrix4d> m_targets;
		double m_control_gain;
		bool m_wdls_jac;
		Eigen::Matrix4d p1;
		Eigen::Matrix4d p2;
		Eigen::Matrix4d p3;
		Eigen::Matrix4d p4;
		std::vector<Eigen::Matrix4d> previous;
		std::vector<double> x_l;
		std::vector<double> y_l;
		std::vector<double> z_l;
		Eigen::MatrixXd error_integrate;

		std::default_random_engine generator;
		std::normal_distribution<double> dist;

		const double mean = 0.1;
  		const double stddev = 0.01;

		std::ofstream myfile;


  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

	public:
		MainLoop(Visualizer* vis, TDCRModelDVS* tdcr, double timestep, int area);
		~MainLoop();
	
		virtual void Execute(vtkObject *vtkNotUsed(caller), unsigned long eventId, void *vtkNotUsed(callData));
    void MoveMotor1(int position);
    void MoveMotor2(int position);
    int ConvertQM(double q);
};

