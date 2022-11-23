
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
