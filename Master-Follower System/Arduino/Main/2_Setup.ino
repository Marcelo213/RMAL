
void setup() {

   // Code from Linear Actuator
    pinMode(STEPPIN, OUTPUT);
    pinMode(DIRPIN, OUTPUT);
    pinMode(ENAPIN, OUTPUT); // I disabled the code about the enable line because this code is using a TB6600 but we have a different IC

    Serial.begin(115200);
    Serial.println("Getting Started ");
    Serial.setTimeout(2);
  
  // LINEAR TRANSLATION
    pinMode(CATHETER_LINEAR_POSITIVE_PIN, OUTPUT);
    pinMode(CATHETER_LINEAR_GROUND_PIN, OUTPUT);
    pinMode(CATHERER_LINEAR_PWM_PIN, OUTPUT);
    pinMode(CATHETER_LINEAR_DIR_A_PIN, OUTPUT);
    pinMode(CATHETER_LINEAR_DIR_B_PIN, OUTPUT);

    digitalWrite(CATHETER_LINEAR_POSITIVE_PIN, HIGH);   // +5V
    digitalWrite(CATHETER_LINEAR_GROUND_PIN, LOW);    // GND
    analogWrite(CATHERER_LINEAR_PWM_PIN, 0);       // Always default to off state
    digitalWrite(CATHETER_LINEAR_DIR_A_PIN, LOW);   // off state
    digitalWrite(CATHETER_LINEAR_DIR_B_PIN, LOW);   // off state


  // BENDING
    pinMode(CATHETER_BENDING_POSITIVE_PIN, OUTPUT);
    pinMode(CATHETER_BENDING_GROUND_PIN, OUTPUT);
    pinMode(CATHERER_BENDING_PWM_PIN, OUTPUT);
    pinMode(CATHETER_BENDING_DIR_A_PIN, OUTPUT);
    pinMode(CATHETER_BENDING_DIR_B_PIN, OUTPUT);

    digitalWrite(CATHETER_BENDING_POSITIVE_PIN, HIGH);   // +5V
    digitalWrite(CATHETER_BENDING_GROUND_PIN, LOW);    // GND
    analogWrite(CATHERER_BENDING_PWM_PIN, 0);       // Always default to off state
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);   // off state
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);   // off state

  
  // ROTATION PINS SETUP
    pinMode(CATHETER_ROTATION_POSITIVE_PIN, OUTPUT);
    pinMode(CATHETER_ROTATION_GROUND_PIN, OUTPUT);
    pinMode(CATHERER_ROTATION_PWM_PIN, OUTPUT);
    pinMode(CATHETER_ROTATION_DIR_A_PIN, OUTPUT);
    pinMode(CATHETER_ROTATION_DIR_B_PIN, OUTPUT);

    digitalWrite(CATHETER_ROTATION_POSITIVE_PIN, HIGH);   // +5V
    digitalWrite(CATHETER_ROTATION_GROUND_PIN, LOW);    // GND
    analogWrite(CATHERER_ROTATION_PWM_PIN, 0);       // Always default to off state
    digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);   // off state
    digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);   // off state
  

  delay(500); // This delay allows the system time to settle and to accurately execute commands 
  


