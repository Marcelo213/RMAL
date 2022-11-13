// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
// ------- DECLARATIONS -- ------- ------- ------- ------- ------- ------- ------- -------
// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
 
  #include <Servo.h>
  #include <Adafruit_PWMServoDriver.h>
  #include <Wire.h>




  int pwmValue;  // pwm value
  int potValue; // potentiometer value

  long pin_select = 0;
  long pin_value = 0; 

  long motor_select = 0;
  long motor_speed = 0;

  long servo_select = 0;
  long servo_angle = 0;
 
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


