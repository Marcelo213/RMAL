void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  //stream.flush();
  //Keyboard.begin();
  //motor_1.attach(MOTOR_1_PWM, 1000, 2000); // attaches the servo on pin 18 to the servo object

  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  Serial.println("Program Starting...");
  delay(1000);




  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
}
