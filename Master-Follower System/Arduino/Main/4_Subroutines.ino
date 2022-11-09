

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

    
long ASSIST_LINEAR_ENCODER_POSITION = p1;
long ASSIST_ROTATION_ENCODER_POSITION = p3;
long CATHETER_BENDING_ENCODER_POSITION = p2;
long CATHETER_ROTATION_ENCODER_POSITION = p4;

  
    Serial.print("Assist Assembly  ");
    Serial.print("Linear: ");
    Serial.print(ASSIST_LINEAR_ENCODER_POSITION);
    Serial.print("\t Rotation: ");
    Serial.print(ASSIST_ROTATION_ENCODER_POSITION);
    Serial.print("\t\tCatheter Assembly  ");
    Serial.print("Bending: ");
    Serial.print(CATHETER_BENDING_ENCODER_POSITION);
    Serial.print(" Rotation: ");
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
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}

void CATHETER_ROTATION_MOVE(int duration){
  Serial.println(duration);
  if (duration < 0){
    digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH); 
  } else {
    digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW); 
  }


   analogWrite(CATHETER_ROTATION_PWM_PIN,255);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(CATHETER_ROTATION_PWM_PIN,0);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);
}

// FOR ASSIST SUBASSEMBLY
void ASSIST_LINEAR_MOVE(int duration) {
  Serial.println(duration);
  if (duration < 0){
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW); 
  } else {
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH);

  }
    duration = abs(duration);
    Serial.println(duration);
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
  analogWrite(ASSIST_ROTATION_PWM_PIN,255);
  delay(duration);
  analogWrite(ASSIST_ROTATION_PWM_PIN,0);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);
}