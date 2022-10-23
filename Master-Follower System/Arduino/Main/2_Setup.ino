
void setup() {

   // Code from Linear Actuator
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT); // I disabled the code about the enable line because this code is using a TB6600 but we have a different IC


  
  Serial.begin(115200);
  Serial.println("Getting Started ");
  Serial.setTimeout(2);

  // PIN SETUP
  
  // LINEAR TRANSLATION
  pinMode(pos1, OUTPUT);
  pinMode(neg1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir1a, OUTPUT);
  pinMode(dir1b, OUTPUT);
  digitalWrite(pos1, HIGH);   // +5V
  digitalWrite(neg1, LOW);    // GND
  analogWrite(pwm1, 0);       // Always default to off state
  digitalWrite(dir1a, LOW);   // off state
  digitalWrite(dir1b, LOW);   // off state


  // BENDING
  pinMode(pos2, OUTPUT);
  pinMode(neg2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir2a, OUTPUT);
  pinMode(dir2b, OUTPUT);
  digitalWrite(pos2, HIGH);
  digitalWrite(neg2, LOW);
  analogWrite(pwm2, 0);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, LOW);

  
  // ROTATION
  pinMode(pos3, OUTPUT);
  pinMode(neg3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dir3a, OUTPUT);
  pinMode(dir3b, OUTPUT);
  digitalWrite(pos3, HIGH);
  digitalWrite(neg3, LOW);
  analogWrite(pwm3, 0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW);
  




  // TESTING MOVEMENT:

  delay(500); // This delay allows the system time to settle and to accurately execute commands 
  
  // Linear Actuator
 // linear_forward(500);
  //linear_backward(500);

  // Taut Mechanism
  //taut_forward(500);
  //taut_backward(500);
  
  // Bending
 // bending_cw(500);
  bending_ccw(500); // There is currently no inputs to the bending function
  
  // Rotation
  //rotating_ccw(500); //parameter is in duration of microseconds
  rotating_cw(500);
}

