
void setup() {


  // Code from Linear Actuator
    pinMode(STEPPIN, OUTPUT);
    pinMode(DIRPIN, OUTPUT);
    pinMode(ENAPIN, OUTPUT); 

    
    Serial.begin(19200);
    Serial.println("Getting Started ");


  // CATHETER ASSEMBLY

    // BENDING
    
      pinMode(CATHETER_BENDING_PWM_PIN, OUTPUT);
      pinMode(CATHETER_BENDING_DIR_A_PIN, OUTPUT);
      pinMode(CATHETER_BENDING_DIR_B_PIN, OUTPUT);

      
      analogWrite(CATHETER_BENDING_PWM_PIN, 0);       // Always default to off state
      digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);   // off state
      digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);   // off state
    
    // ROTATION
      
      pinMode(CATHETER_ROTATION_PWM_PIN, OUTPUT);
      pinMode(CATHETER_ROTATION_DIR_A_PIN, OUTPUT);
      pinMode(CATHETER_ROTATION_DIR_B_PIN, OUTPUT);

      
      analogWrite(CATHETER_ROTATION_PWM_PIN, 0);       // Always default to off state
      digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);   // off state
      digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);   // off state
  //
  Serial.println("Check 1");
  // ASSIST ASSEMBLY
    // LINEAR TRANSLATION
     
      pinMode(ASSIST_LINEAR_PWM_PIN, OUTPUT);
      pinMode(ASSIST_LINEAR_DIR_A_PIN, OUTPUT);
      pinMode(ASSIST_LINEAR_DIR_B_PIN, OUTPUT);

      
      analogWrite(ASSIST_LINEAR_PWM_PIN, 0);       // Always default to off state
      digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);   // off state
      digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);   // off state
    //
    

    // ROTATION PINS SETUP
      
      pinMode(ASSIST_ROTATION_PWM_PIN, OUTPUT);
      pinMode(ASSIST_ROTATION_DIR_A_PIN, OUTPUT);
      pinMode(ASSIST_ROTATION_DIR_B_PIN, OUTPUT);

      
      analogWrite(ASSIST_ROTATION_PWM_PIN, 0);       // Always default to off state
      digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);   // off state
      digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);   // off state
    //
  //

  //Serial.println("Ready.");
 
  //ACTUATOR_MOVE(1000); // 1000 steps is about 27mm
  
  //setPoint = 0;                          //set point at zero degrees

}

