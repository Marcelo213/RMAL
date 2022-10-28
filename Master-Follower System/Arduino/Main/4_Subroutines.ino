
// FOR LINEAR ACTUATOR
  /*void linear_forward(int steps){
    int i;
    digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
    digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
    for(i=0;i<steps;i++){
      digitalWrite(STEPPIN,HIGH);
      delayMicroseconds(STEPTIME);
      digitalWrite(STEPPIN,LOW);
      delayMicroseconds(STEPTIME);
    }
    digitalWrite(ENAPIN,LOW);//DISABLE STEPPER


        // MOVING THE TAUT MECHANISM FORWARD
      analogWrite(pwm1, 100);       // Always default to off state
      digitalWrite(dir1a, HIGH);   // off state
      digitalWrite(dir1b, LOW);   // off state
      
  }
  void linear_backward(int steps){
    int i;
    digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
    digitalWrite(DIRPIN,LOW);//SET DIRECTION 
    for(i=0;i<steps;i++){
      digitalWrite(STEPPIN,HIGH);
      delayMicroseconds(STEPTIME);
      digitalWrite(STEPPIN,LOW);
      delayMicroseconds(STEPTIME);
    }
    digitalWrite(ENAPIN,LOW);//DISABLE STEPPER
*/

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
    Serial.print(p1);
    Serial.print(" ");
    Serial.print(p2);
    Serial.print(" ");
    Serial.println(p3);
}

// FOR CATHETER ASSEMBLY
void CATHETER_BENDING_CW(int duration){
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, HIGH);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW); 
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}
void CATHETER_BENDING_CCW(int duration){
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, HIGH); 
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}

// FOR ASSIST SUBASSEMBLY
void ASSIST_LINEAR_FORWARD(int duration) {
    analogWrite(ASSIST_LINEAR_PWM_PIN,255);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW); 
    delay(duration);
    analogWrite(ASSIST_LINEAR_PWM_PIN,0);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
}

void ASSIST_LINEAR_BACKWARD(int duration) {
  analogWrite(ASSIST_LINEAR_PWM_PIN,255);
  digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(ASSIST_LINEAR_PWM_PIN,0);
  digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
}

void ASSIST_ROTATING_CW(int duration) {
  analogWrite(ASSIST_ROTATION_PWM_PIN,255);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW); 
  delay(duration);
  analogWrite(ASSIST_ROTATION_PWM_PIN,0);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);
}
  
void ASSIST_ROTATING_CCW(int duration) {
  analogWrite(ASSIST_ROTATION_PWM_PIN, 255);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(ASSIST_ROTATION_PWM_PIN,0);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW); 
}
//

// FOR CATHETER-ASSEMBLY
 /* void bending_cw(int duration){
    analogWrite(pwm2,100);
    digitalWrite(dir2a, HIGH);
    digitalWrite(dir2b, LOW); 
    delay(duration);
    analogWrite(pwm2,0);
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, LOW);
  }
  void bending_ccw(int duration){
      analogWrite(pwm2,255);
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, HIGH); 
    delay(duration);
    analogWrite(pwm2,0);
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, LOW); 
  }*/
  

