void setup() {
  Serial.begin(115200);
  // Allow allocation of all timers
  /*ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);*/
  //motor_1.setPeriodHertz(50);    // standard 50 hz servo
  motor_1.attach(MOTOR_1_PWM, 1000, 2000); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}
