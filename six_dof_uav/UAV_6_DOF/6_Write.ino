/// @brief Commands all motors and servos to run
void Write(){

  // Arm 1
  double Arm_1_Upper_Motor_PWM = map(Arm_1.Upper_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_1_Upper_Motor_Index, Arm_1_Upper_Motor_PWM);
  double Arm_1_Lower_Motor_PWM = map(Arm_1.Lower_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_1_Lower_Motor_Index, Arm_1_Lower_Motor_PWM);
  double Arm_1_Servo_PWM = map(Arm_1.Servo_Angle, 0, 180, 600, 2400);   // 0 - 180 because of angle ; SERVO
   pwm.writeMicroseconds(Arm_1_Servo_Index, Arm_1_Servo_PWM);

   // Arm 2
  double Arm_2_Upper_Motor_PWM = map(Arm_2.Upper_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_2_Upper_Motor_Index, Arm_2_Upper_Motor_PWM);
  double Arm_2_Lower_Motor_PWM = map(Arm_2.Lower_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_2_Lower_Motor_Index, Arm_2_Lower_Motor_PWM);
  double Arm_2_Servo_PWM = map(Arm_2.Servo_Angle, 0, 180, 600, 2400);   // 0 - 180 because of angle ; SERVO
   pwm.writeMicroseconds(Arm_2_Servo_Index, Arm_2_Servo_PWM);

   // Arm 3
  double Arm_3_Upper_Motor_PWM = map(Arm_3.Upper_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_3_Upper_Motor_Index, Arm_3_Upper_Motor_PWM);
  double Arm_3_Lower_Motor_PWM = map(Arm_3.Lower_Motor_Duty_Cycle, 0, 100, 900, 2000);  // 0 - 100 because of duty cycle ; MMOTOR
    pwm.writeMicroseconds(Arm_3_Lower_Motor_Index, Arm_3_Lower_Motor_PWM);
  double Arm_3_Servo_PWM = map(Arm_3.Servo_Angle, 0, 180, 600, 2400);   // 0 - 180 because of angle ; SERVO
    pwm.writeMicroseconds(Arm_3_Servo_Index, Arm_3_Servo_PWM);


}