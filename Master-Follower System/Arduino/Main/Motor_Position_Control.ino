






 void PID_Controller(){

  /* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
    
    The following is the work on the development of P control of theta in the assist roation motor

  */
  // ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----


  currentTime = millis();                //get current time
  elapsedTime = (double)(currentTime - previousTime); 

  // ------ Reads the current encoder data in rads
  Current_Pose.theta = get_rad_convert_ASSIST_ASSEMBLY(get_rad_350( ASSIST_ROTATION_ENCODER.read())) ; 
  
  //Current_Pose.theta = get_rad_1000(CATHETER_ROTATION_ENCODER.read()) ; 

  Serial.print("Current theta in rads: ");
  Serial.print(Current_Pose.theta, 5);                          // ---- Prints with 5 decimal accuracy

  // ------ Calculates the steady-state error
  double THETA_ERROR = Target_Pose.theta - Current_Pose.theta;
  cumError += THETA_ERROR * elapsedTime;                // compute integral
  rateError = (THETA_ERROR - lastError)/elapsedTime;        // compute derivative

  lastError = THETA_ERROR;                                //remember current error
  previousTime = currentTime;                        //remember current time

  double PID_output = kp*THETA_ERROR + ki*cumError + kd*rateError;                //PID output; error in rad          

  // ------ Allows the motor to rotate both ways
  if (PID_output < 0){
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


  PID_output = abs(PID_output);
  PID_output = constrain(PID_output, 0, PI );
  PID_output = map(PID_output, 0, PI, 0, 255);
  analogWrite(ASSIST_ROTATION_PWM_PIN, PID_output);

  // NEED P CONSTANT OF 50 IN CATH ASSEMVLY
  //analogWrite(CATHETER_ROTATION_PWM_PIN, pwm_signal_motor_2);

  Serial.print("\tCurrent theta ERROR in rads: ");
  Serial.print(THETA_ERROR);

  Serial.print("\tCurrent 'PID_output' in PWM ");
  Serial.println(PID_output);

 

 }

