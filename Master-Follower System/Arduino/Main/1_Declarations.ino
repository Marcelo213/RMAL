#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS

const int STEPTIME = 1000; // in microseconds; controls the speed of the linear actuator

//  PIN LABELS
// char move1, move2, move3;

// CATHETER ASSEMBLY
  // BENDING
    long p2 = 0;             // Encoder Current Position   (internal)
    long np2O = 0;           // Encoder Previous Position  (internal)
    Encoder CATHETER_BENDING_ENCODER(CATHETER_BENDING_ENCODER_A_PIN, CATHETER_BENDING_ENCODER_B_PIN);  // Encoder Variable
  //
  // ROTATION
    long p4 = 0;             // Encoder Current Position   (internal)
    long np4O = 0;           // Encoder Previous Position  (internal)
    Encoder CATHETER_ROTATION_ENCODER(CATHETER_ROTATION_ENCODER_A_PIN, CATHETER_ROTATION_ENCODER_B_PIN);
//

// ASSIST ASSEMBLY

  // LINEAR TRANSLATION
    long p1 = 0;          // Encoder Current Position   (internal)
    long np1O = 0;        // Encoder Previous Position  (internal)
    Encoder ASSIST_LINEAR_ENCODER(ASSIST_LINEAR_ENCODER_A_PIN, ASSIST_LINEAR_ENCODER_B_PIN);  // Encoder Variable
  //

  // ROTATION
    long p3 = 0;            // Encoder Current Position   (internal)
    long np3O = 0;          // Encoder Previous Position  (internal)
    Encoder ASSIST_ROTATION_ENCODER(ASSIST_ROTATION_ENCODER_A_PIN, ASSIST_ROTATION_ENCODER_B_PIN);  // Encoder Variable
  //

//

uint64_t loop1Time100Hz = 0;
long ASSIST_LINEAR_ENCODER_POSITION = 0;
long ASSIST_ROTATION_ENCODER_POSITION = 0;
long CATHETER_BENDING_ENCODER_POSITION = 0;
long CATHETER_ROTATION_ENCODER_POSITION = 0;


double error_motor_1;
double ASSIST_ROTATION_THETA_ERROR;
double error_motor_3;
double error_motor_4;
double error_motor_5;


double Motor_1_Theta_Rad = 0;
double Motor_2_Theta_Rad = 0;
double Motor_3_Theta_Rad = 0;
double Motor_4_Theta_Rad = 0;
double Motor_5_Theta_Rad = 0;


//double PI = 3.1415926535897932384626;

int ENCODER_RESOLUTION = 100;

struct pos {
  double x;                           // Linear Position in mm
  double theta;                       // Rotation Position in rads
  double phi;                         // Bending position
};
typedef struct pos Pose;
/*
  Note that the following poses are organized as follows:

  Motor 1 = Assist Linear Motor
  Motor 2 = Assist Rotation Motor
  Motor 3 = Catheter Bending Motor
  Motor 4 = Catheter Rotation Motor
  Motor 5 = Linear Actuator
    
*/
Pose Current_Pose = {0, 0, 0};
Pose Target_Pose = {0, 0, 0};


  unsigned long currentTime, previousTime;
  double elapsedTime;







  double error;
  double lastError;
  double cumError_theta1, rateError_theta1;

  double error_2;
  double lastError_theta2;
  double cumError_theta2, rateError_theta2;


  double error_temp;
  double lastError_temp;
  double cumError_temp, rateError_temp;


  int motor_select;
  double rad_increment;





    double LAST_ERROR_LINEAR_1;
   double INTEGRAL_ERROR_LINEAR_1;
   double DERIVATIVE_ERROR_LINEAR_1;

  double LAST_ERROR_PHI;
   double INTEGRAL_ERROR_PHI;
   double DERIVATIVE_ERROR_PHI;



  double x2_lastPosition = 0;
  double x2 = 0; 
