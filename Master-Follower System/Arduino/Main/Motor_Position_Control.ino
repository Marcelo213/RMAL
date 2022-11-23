






 void P_Controller(){

    /*
      The following is the work on the development of P control of theta in the assist roation motor

*/
  
  // Reads the current encoder data in rads
  Current_Pose.theta = get_rad_350( ASSIST_ROTATION_ENCODER.read()) ; 
    //Current_Pose.theta = get_rad_1000(CATHETER_ROTATION_ENCODER.read()) ; 

  Serial.print("Current theta in rads: ");
  Serial.print(Current_Pose.theta, 5);                          // ---- Prints with 5 decimal accuracy
  // ------ Calculates the steady-state error
  double THETA_ERROR = Target_Pose.theta - Current_Pose.theta;

  // ----- This prevents the motor from overshooting 
  //if (abs(THETA_ERROR) < ENCODER_RESOLUTION) {   
  //}

  // ------ Allows the motor to rotate both ways
  if (THETA_ERROR < 0){
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);  
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH);  

  } else {
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);  
    }

  // ------- Proportional Gain
  int P_constant = 3; 


// NEED P CONSTANT OF 50 IN CATH ASSEMVLY
  int pwm_signal_motor_2 = map(abs(THETA_ERROR * P_constant), 0, 2*PI, 0, 255);

  

  analogWrite(ASSIST_ROTATION_PWM_PIN, pwm_signal_motor_2);
  //analogWrite(CATHETER_ROTATION_PWM_PIN, pwm_signal_motor_2);

  Serial.print("\tCurrent theta ERROR in rads: ");
  Serial.println(THETA_ERROR);

 

 }

