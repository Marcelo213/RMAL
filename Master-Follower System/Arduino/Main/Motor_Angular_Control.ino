
/*
  Motor 1: 350 rating
  Motor 2: 350 rating
  Motor 3: 1000 rating
  Motor 4: 1000 rating
    
  Encoder value calculation
  Encoder pulse per revolution = 28
  so one rotation of output shaft = Encoder pulse per revolution X Gear Ratio
  So pulse per one rotation = 28 X 100
  = 2800 Pulse per revolution

  PID Information Link: https://www.teachmemicro.com/arduino-pid-control-tutorial/#:~:text=To%20implement%20a%20PID%20controller,value%20and%20set%20point%20value.&text=1-,output%20%3D%20Kp%20*%20error%20%2B%20Ki%20*%20cumError%20%2B%20Kd%20*,Kd%20are%20the%20predetermined%20constants.
*/

 void P_Controller(){
  
    // ------ Calculates the steady-state error
  double ASSIST_ROTATION_CURRENT_THETA = ASSIST_ROTATION_ENCODER.read(); 

    double ASSIST_ROTATION_THETA_ERROR = Motor_2_Theta_Rad - ASSIST_ROTATION_RAD;


    // ----- This prevents the motor from overshooting 
    if (abs(ASSIST_ROTATION_THETA_ERROR) < ENCODER_RESOLUTION) {   
    }

    // ------ Allows the motor to rotate both ways
    if (ASSIST_ROTATION_THETA_ERROR < 0){
    digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);  
    } else {
    digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
     }
  
    // ------- Proportional Gain
    int pwm_signal_motor_2 = abs(ASSIST_ROTATION_THETA_ERROR * P_constant);
  
    //pwm_signal = constrain(pwm_signal, 0, 255);

    analogWrite(ASSIST_ROTATION_PWM_PIN, pwm_signal_motor_2);
    //Serial.println(pwm_signal_motor_2);
    //Serial.println(ASSIST_ROTATION_THETA_ERROR);
  
  



 }

