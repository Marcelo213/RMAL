void loop() {


// NOTE: Need to fix servo on pin 2 so that 90 deg is parallel to the ground.


  if (Serial.available() > 0) {

    // Motors are 0,1 | 4,5 | 8,9
    // Servos are 2 | 6 | 10

    Arm_1.Upper_Motor_Duty_Cycle = Serial.parseInt();
    Arm_1.Lower_Motor_Duty_Cycle = Serial.parseInt();
    Arm_1.Servo_Angle = Serial.parseInt();

    Arm_2.Upper_Motor_Duty_Cycle = Serial.parseInt();
    Arm_2.Lower_Motor_Duty_Cycle = Serial.parseInt();
    Arm_2.Servo_Angle = Serial.parseInt();

    Arm_3.Upper_Motor_Duty_Cycle = Serial.parseInt();
    Arm_3.Lower_Motor_Duty_Cycle = Serial.parseInt();
    Arm_3.Servo_Angle = Serial.parseInt();
   
  }
  
  
  Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\tY : ");
	Serial.print(mpu.getAngleY());
	Serial.print("\tZ : ");
	Serial.print(mpu.getAngleZ());

  Serial.print(Arm_1.Upper_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_1.Lower_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_1.Servo_Angle);
  Serial.print("\t");
  Serial.print(Arm_2.Upper_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_2.Lower_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_2.Servo_Angle);
  Serial.print("\t");
  Serial.print(Arm_3.Upper_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_3.Lower_Motor_Duty_Cycle);
  Serial.print("\t");
  Serial.print(Arm_3.Servo_Angle);
  Serial.print("\t");

  Serial.print("Sensor Reading (mm): ");
  Serial.print(sensor.read());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }


  Serial.println();

  //send_command();

  //get_Angle();
  Write();
  


  }
