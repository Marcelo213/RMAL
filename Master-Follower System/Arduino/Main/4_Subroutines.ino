

// FOR ENCODER
void read_encoder(){
  // READING ENCODERS: 
    // - LINEAR TRANSLATION
    long np1 = ASSIST_LINEAR_ENCODER.read();
    if (np1 != np1O) {
      np1O = np1;
      p1 = np1;
      }

    // - BENDING
    long np2 = CATHETER_BENDING_ENCODER.read();
    if (np2 != np2O) {
      np2O = np2;
      p2 = np2;
      }

    // - ROTATION
      long np3 = ASSIST_ROTATION_ENCODER.read();
      if (np3 != np3O) {
      np3O = np3;
      p3 = np3;
      }

      // - ROTATION
      long np4 = CATHETER_ROTATION_ENCODER.read();
      if (np4 != np4O) {
      np4O = np4;
      p4 = np4;
      }

    
  ASSIST_LINEAR_ENCODER_POSITION = p1;
  ASSIST_ROTATION_ENCODER_POSITION = p3;
  CATHETER_BENDING_ENCODER_POSITION = p2;
  CATHETER_ROTATION_ENCODER_POSITION = p4;

  
    
    Serial.print("A: ");
    Serial.print(ASSIST_LINEAR_ENCODER_POSITION);
    Serial.print("\tB: ");
    Serial.print(ASSIST_ROTATION_ENCODER_POSITION);
    Serial.print("\tC  ");
    Serial.print(CATHETER_BENDING_ENCODER_POSITION);
    Serial.print("\tD ");
    Serial.println(CATHETER_ROTATION_ENCODER_POSITION);
    
}

// FOR LINEAR ACTUATOR
  void ACTUATOR_MOVE(int steps){
      if (steps < 0){
      digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
      } else {
      digitalWrite(DIRPIN,LOW);//SET DIRECTION 
      }    
     int i;
     steps = abs(steps);
      digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
      for(i=0;i<steps;i++){
      digitalWrite(STEPPIN,HIGH);
      delayMicroseconds(STEPTIME);
      digitalWrite(STEPPIN,LOW);
      delayMicroseconds(STEPTIME);
      }
    digitalWrite(ENAPIN,LOW);//DISABLE STEPPER  
  }

// FOR CATHETER ASSEMBLY
void CATHETER_BENDING_MOVE(int duration){
  if (duration < 0){
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, HIGH);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW); 
  } else {
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, HIGH); 
  }
    duration = abs(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}

void CATHETER_ROTATION_MOVE(int duration){
  if (duration < 0){
    digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH); 
  } else {
    digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW); 
  }

  duration = abs(duration);
  analogWrite(CATHETER_ROTATION_PWM_PIN,255);
  delay(duration);
  analogWrite(CATHETER_ROTATION_PWM_PIN,0);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);
}

// FOR ASSIST SUBASSEMBLY
void ASSIST_LINEAR_MOVE(int duration) {
  if (duration < 0){
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW); 
  } else {
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH);

  }
    duration = abs(duration);
    analogWrite(ASSIST_LINEAR_PWM_PIN,255);
    delay(duration);
    analogWrite(ASSIST_LINEAR_PWM_PIN,0);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
}

void ASSIST_ROTATION_MOVE(int duration) {
  if (duration < 0){
    digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);  
  } else {
    digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
  }
    duration = abs(duration);
    analogWrite(ASSIST_ROTATION_PWM_PIN,255);
    delay(duration);
    analogWrite(ASSIST_ROTATION_PWM_PIN,0);
    digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

  PID Link: https://www.teachmemicro.com/arduino-pid-control-tutorial/#:~:text=To%20implement%20a%20PID%20controller,value%20and%20set%20point%20value.&text=1-,output%20%3D%20Kp%20*%20error%20%2B%20Ki%20*%20cumError%20%2B%20Kd%20*,Kd%20are%20the%20predetermined%20constants.
*/

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



