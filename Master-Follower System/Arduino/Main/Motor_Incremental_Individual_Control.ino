/*
Motor Options:
1 = Assist_linear
2 = Assist_rotation
3 = Catheter_bending
4 = Catheter_rotation
5 = Linear_actuator

Rad: Position is in absolute; can be negative 
*/

/*
void PID_Position_Controller_Individual(){
  double kp_temp = 0.001;
  double ki_temp = 0.00001;
  double kd_temp = 0;

  currentTime = millis();                //get current time
  elapsedTime = (double)(currentTime - previousTime); 


  /*

  WARNING: Be careful of motor direction. IT HAS NOT BEEN TESTED

  */
/*
  // ------ Reads the current encoder data in rads
  switch (motor_select){
    case 0:
    break;
    case 1:
      Current_Pose.theta = get_rad_convert_ASSIST_ASSEMBLY(get_rad_300( ASSIST_LINEAR_ENCODER.read())) ;    // This is the theta of the assist assembly
      break;
    case 2:
      Current_Pose.theta = get_rad_convert_ASSIST_ASSEMBLY(get_rad_300( ASSIST_ROTATION_ENCODER.read())) ;    // This is the theta of the assist assembly
      break;
    case 3:
      Current_Pose.theta = get_rad_convert_CATHETER_ASSEMBLY(get_rad_1000( -1* CATHETER_BENDING_ENCODER.read()));
      break;
    case 4:
      Current_Pose.theta = get_rad_convert_CATHETER_ASSEMBLY(get_rad_1000( -1* CATHETER_ROTATION_ENCODER.read()));
      break;
  }


  Serial.print("Current theta in rads: ");
  Serial.print(Current_Pose.theta, 5);                          // ---- Prints with 5 decimal accuracy

  // ------ Calculates the steady-state error
  double THETA_ERROR = Target_Pose.theta - Current_Pose.theta;
  cumError_temp += THETA_ERROR * elapsedTime;                // compute integral
  rateError_temp = (THETA_ERROR - lastError)/elapsedTime;        // compute derivative

  lastError_temp = THETA_ERROR;                                //remember current error
  previousTime = currentTime;                        //remember current time

  double PID_output_temp = kp_temp*THETA_ERROR + ki_temp*cumError_temp + kd_temp*rateError_temp;                //PID output; error in rad          

  // ------ Allows the motor to rotate both ways
  
  switch (motor_select){
    case 0:
    break;
    case 1:
      if (PID_output_temp < 0){
        digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
        digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);  
      } else {
        digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
        digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH); 
      }
    break;
    case 2:
      if (PID_output_temp < 0){
        digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
        digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);  
      } else {
        digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
        digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
      }
    break;
    case 3:
      if (PID_output_temp < 0){
        digitalWrite(CATHETER_BENDING_DIR_A_PIN, HIGH);
        digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);  
      } else {
        digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
        digitalWrite(CATHETER_BENDING_DIR_B_PIN, HIGH); 
      }
    break;
    case 4:
      if (PID_output_temp < 0){
        digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
        digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);  
      } else {
        digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
        digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH); 
      }
    break;
  }


  PID_output_temp = abs(PID_output_temp);
  PID_output_temp = constrain(PID_output_temp, 0, 2*PI);               // Resolution is being improved by increasing the constrain limits
  PID_output_temp = map(PID_output_temp, 0, 2*PI, 0, 255);
  analogWrite(ASSIST_ROTATION_PWM_PIN, PID_output_temp);

}*/