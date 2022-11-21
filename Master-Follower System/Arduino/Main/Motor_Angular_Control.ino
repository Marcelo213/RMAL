
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


// ------ This subroutine will probably need a PID made for it
void ASSIST_LINEAR_MOVE_THETA(int delta_theta) {
  int target_pose_theta = ASSIST_LINEAR_ENCODER_POSITION + delta_theta;
 
  if (delta_theta < 0){
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW); 
  } else {
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH);

  } if (20 > abs(ASSIST_LINEAR_ENCODER_POSITION-target_pose_theta)){
      analogWrite(ASSIST_LINEAR_PWM_PIN,255);
    } else {
    analogWrite(ASSIST_LINEAR_PWM_PIN,0);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
    }
}

