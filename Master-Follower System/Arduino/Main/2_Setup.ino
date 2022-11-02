
void setup() {

  // Clear out buffer.
  while(Serial.read() >= 0) ;


  //Serial.println("Here ");
  // CATHETER ASSEMBLY

    // Code from Linear Actuator
      pinMode(STEPPIN, OUTPUT);
      pinMode(DIRPIN, OUTPUT);
      pinMode(ENAPIN, OUTPUT); // I disabled the code about the enable line because this code is using a TB6600 but we have a different IC

      Serial.begin(115200);
      Serial.println("Getting Started ");
      //  Serial.setTimeout(2);
    //

    // BENDING
    //Serial.println("Here");
      //pinMode(CATHETER_BENDING_POSITIVE_PIN, OUTPUT);
      //pinMode(CATHETER_BENDING_GROUND_PIN, OUTPUT);
      pinMode(CATHERER_BENDING_PWM_PIN, OUTPUT);
      pinMode(CATHETER_BENDING_DIR_A_PIN, OUTPUT);
      pinMode(CATHETER_BENDING_DIR_B_PIN, OUTPUT);

      //digitalWrite(CATHETER_BENDING_POSITIVE_PIN, HIGH);   // +5V
      //digitalWrite(CATHETER_BENDING_GROUND_PIN, LOW);    // GND
      analogWrite(CATHERER_BENDING_PWM_PIN, 0);       // Always default to off state
      digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);   // off state
      digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);   // off state
    //
    // ROTATION
      //pinMode(CATHETER_BENDING_POSITIVE_PIN, OUTPUT);
      //pinMode(CATHETER_BENDING_GROUND_PIN, OUTPUT);
      pinMode(CATHETER_ROTATION_PWM_PIN, OUTPUT);
      pinMode(CATHETER_ROTATION_DIR_A_PIN, OUTPUT);
      pinMode(CATHETER_ROTATION_DIR_B_PIN, OUTPUT);

      //digitalWrite(CATHETER_BENDING_POSITIVE_PIN, HIGH);   // +5V
      //digitalWrite(CATHETER_BENDING_GROUND_PIN, LOW);    // GND
      analogWrite(CATHETER_ROTATION_PWM_PIN, 0);       // Always default to off state
      digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);   // off state
      digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);   // off state
  //
  Serial.println("Check 1");


  // ASSIST ASSEMBLY
    // LINEAR TRANSLATION
     // pinMode(ASSIST_LINEAR_POSITIVE_PIN, OUTPUT);
      //pinMode(ASSIST_LINEAR_GROUND_PIN, OUTPUT);
      pinMode(ASSIST_LINEAR_PWM_PIN, OUTPUT);
      pinMode(ASSIST_LINEAR_DIR_A_PIN, OUTPUT);
      pinMode(ASSIST_LINEAR_DIR_B_PIN, OUTPUT);

      //digitalWrite(ASSIST_LINEAR_POSITIVE_PIN, HIGH);   // +5V
      //digitalWrite(ASSIST_LINEAR_GROUND_PIN, LOW);    // GND
      analogWrite(ASSIST_LINEAR_PWM_PIN, 0);       // Always default to off state
      digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);   // off state
      digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);   // off state
    //
    Serial.println("Check 2");

    // ROTATION PINS SETUP
      //pinMode(ASSIST_ROTATION_POSITIVE_PIN, OUTPUT);
      //pinMode(ASSIST_ROTATION_GROUND_PIN, OUTPUT);
      pinMode(ASSIST_ROTATION_PWM_PIN, OUTPUT);
      pinMode(ASSIST_ROTATION_DIR_A_PIN, OUTPUT);
      pinMode(ASSIST_ROTATION_DIR_B_PIN, OUTPUT);

      //digitalWrite(ASSIST_ROTATION_POSITIVE_PIN, HIGH);   // +5V
      //digitalWrite(ASSIST_ROTATION_GROUND_PIN, LOW);    // GND
      analogWrite(ASSIST_ROTATION_PWM_PIN, 0);       // Always default to off state
      digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);   // off state
      digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);   // off state
    //
  //
  Serial.println("Check 3");
  //delay(2000); 
  //Serial.println("Check 4");
  ASSIST_ROTATING_CW(1000);
  delay(1000);
  ASSIST_ROTATING_CCW(1000);
  delay(1500);
  ASSIST_LINEAR_FORWARD(1500);
  //delay(1000);
  //ASSIST_LINEAR_BACKWARD(1500);
  //delay(1000);
  //CATHETER_BENDING_CCW(1000);
  //delay(1000);
  //CATHETER_BENDING_CW(1000);
  
  Serial.println("Movement Example Complete.");
  //delay(2000);
  //CATHETER_BENDING_CCW(500);


  
  

}

