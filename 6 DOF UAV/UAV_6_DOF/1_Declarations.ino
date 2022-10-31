// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
// ------- DECLARATIONS -- ------- ------- ------- ------- ------- ------- ------- -------
// ------- ------- ------- ------- ------- ------- ------- ------- ------- ------- -------
 
  #include <Servo.h>
  #include <Adafruit_PWMServoDriver.h>
  #include <Wire.h>
  //#include <Stream.h>
  //#include "Keyboard.h"
  //Servo motor_1;  // create servo object to control a servo
 

  // our servo # counter
  uint8_t servonum = 0; 

  int pin_state = 0;


  int pwmValue;  // pwm value
  int potValue; // potentiometer value
  int motor_select;
 
  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

  #define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
  #define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
  #define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates




  #include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;


