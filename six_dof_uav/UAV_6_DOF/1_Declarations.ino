// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
// ------- DECLARATIONS -- ------- ------- ------- ------- ------- ------- ------- -------
// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
 
  #include <Servo.h>
  #include <Adafruit_PWMServoDriver.h>
  #include <Wire.h>
  #include <VL53L1X.h>
  VL53L1X sensor;
 
  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

  #define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
  #define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
  #define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
  #define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
  #define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600


  #include "Wire.h"
  #include <MPU6050_light.h>

  MPU6050 mpu(Wire);
  unsigned long timer = 0;


  struct state {
  double Upper_Motor_Duty_Cycle;           //   between 0-100 for motor pins (duty cycle value)
  double Lower_Motor_Duty_Cycle;           //   between 0-100 for motor pins (duty cycle value)
  double Servo_Angle;                      //   be between 0-180 for servo pins (angle value)
  };
  typedef struct state State;

  State Arm_1 = {0, 0, 90};
  State Arm_2 = {0, 0, 90};
  State Arm_3 = {0, 0, 90};

  int Arm_1_Upper_Motor_Index = 0;
  int Arm_1_Lower_Motor_Index = 1;
  int Arm_1_Servo_Index = 2;

  int Arm_2_Upper_Motor_Index = 4;
  int Arm_2_Lower_Motor_Index = 5;
  int Arm_2_Servo_Index = 6;

  int Arm_3_Upper_Motor_Index = 8;
  int Arm_3_Lower_Motor_Index = 9;
  int Arm_3_Servo_Index = 10;

