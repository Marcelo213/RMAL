

void linear_forward(int steps){
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


      /*// MOVING THE TAUT MECHANISM FORWARD
    analogWrite(pwm1, 100);       // Always default to off state
    digitalWrite(dir1a, HIGH);   // off state
    digitalWrite(dir1b, LOW);   // off state
    */
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
}

void read_encoder(){
  
  // READING ENCODERS: 
  // - LINEAR TRANSLATION
  long np1 = en1.read();
  if (np1 != np1O) {
    np1O = np1;
    p1 = np1;
    }

  // - BENDING
  long np2 = en2.read();
  if (np2 != np2O) {
    np2O = np2;
    p2 = np2;
    }

  // - ROTATION
    long np3 = en3.read();
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

void taut_forward(int duration){
  analogWrite(pwm1,150);
  digitalWrite(dir1a, HIGH);
  digitalWrite(dir1b, LOW); 
  delay(duration);
  analogWrite(pwm1,0);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, LOW);
}
void taut_backward(int duration){
  analogWrite(pwm1,100);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, HIGH); 
  delay(duration);
  analogWrite(pwm1,0);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, LOW);
}
void bending_cw(int duration){
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
}
void rotating_cw(int duration){
  analogWrite(pwm3,255);
  digitalWrite(dir3a, HIGH);
  digitalWrite(dir3b, LOW); 
  delay(duration);
  analogWrite(pwm3,0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW);
}
void rotating_ccw(int duration){
    analogWrite(pwm3,255);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, HIGH); 
  delay(duration);
  analogWrite(pwm3,0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW); 
}
