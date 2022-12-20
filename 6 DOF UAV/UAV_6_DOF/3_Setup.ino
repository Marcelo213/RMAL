void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  //pinMode(SWITCH_PIN, INPUT_PULLUP);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  Serial.println("Program Starting...");
  delay(1000);

  // For MPU9250
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");


  for (int i = 0; i <= 10; i++){
    pin_select = i;
    pin_value = 0;
    switch (pin_select) {
    case 0:
      move_Motor();
      break;
    case 1:
      move_Motor();
      break;
    case 2:
      pin_value = 90;
      move_Servo();
      break;
    case 3: // Empty Slot
      break;
    case 4:
      move_Motor();
      break;
    case 5:
      move_Motor();
      break;
    case 6:
      pin_value = 90;
      move_Servo();
      break;
    case 7: // Empty Slot
      break;
    case 8:
      move_Motor();
      break;
    case 9:
      move_Motor();
      break;
    case 10:
      pin_value = 90;
      move_Servo();
      break;
    delay(1000);
  }
  }


}
