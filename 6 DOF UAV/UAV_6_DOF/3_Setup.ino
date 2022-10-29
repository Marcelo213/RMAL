void setup() {
  Serial.begin(115200);
  //stream.flush();
  //Keyboard.begin();
  //motor_1.attach(MOTOR_1_PWM, 1000, 2000); // attaches the servo on pin 18 to the servo object

  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  Serial.println("Program Starting...");
  delay(1000);
}
