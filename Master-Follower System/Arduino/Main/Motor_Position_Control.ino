






 void PID_Position_Controller(){

  /* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
    
    The following is the work on the development of P control of theta in the assist roation motor

  */
  // ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----


  currentTime = millis();                //get current time
  elapsedTime = (double)(currentTime - previousTime); 

  // ------ Reads the current encoder data in rads
  Current_Pose.theta = get_rad_convert_ASSIST_ASSEMBLY(get_rad_350( ASSIST_ROTATION_ENCODER.read())) ;    // This is the theta of the assist assembly
  double theta2 =  get_rad_convert_CATHETER_ASSEMBLY(get_rad_1000( -1* CATHETER_ROTATION_ENCODER.read()));   // This is what the Catheter assembly rad should be; there is a -1 because the encoders are wired the opposite way so the count is in the opposite way

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
  

  } else {
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
   
  }


  PID_output = abs(PID_output);
  PID_output = constrain(PID_output, 0, PI);               // Resolution is being improved by increasing the constrain limits
  PID_output = map(PID_output, 0, PI, 100, 255);
  analogWrite(ASSIST_ROTATION_PWM_PIN, PID_output);





  double THETA_ERROR_2 = Target_Pose.theta - theta2;
  cumError_2 += THETA_ERROR_2 * elapsedTime;                // compute integral
  rateError_2 = (THETA_ERROR_2 - lastError_2)/elapsedTime;        // compute derivative


  lastError_2 = THETA_ERROR_2;                                //remember current error
  previousTime = currentTime;                        //remember current time


  /*  ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----

  Same PID as above but targeted for catheter assembly. Note that they use different PID coefficients

  */// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----

  double PID_output_2 = kp_2*THETA_ERROR_2 + ki_2*cumError_2 + kd_2*rateError_2;                //PID output; error in rad    
  
  if (PID_output_2 < 0){
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);  
  } else {
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH);  
  }

  PID_output_2 = abs(PID_output_2);
  PID_output_2 = constrain(PID_output_2, 0, PI);               // Resolution is being improved by increasing the constrain limits
  PID_output_2 = map(PID_output_2, 0, PI, 100, 255);
  analogWrite(CATHETER_ROTATION_PWM_PIN, PID_output_2);

  Serial.print("\tTHETA_1 ERROR in rads: ");
  Serial.print(THETA_ERROR);

  Serial.print("\tTHETA_2 ERROR in rads: ");
  Serial.print(THETA_ERROR_2);
  
  Serial.print("\tCurrent 'PID_output' in PWM ");
  Serial.println(PID_output);

 




 }

