void loop() {

  if (Serial.available() > 0) {

    // Motors are 0-1
    // Serovs are 15
      
      //TBD: Safety 
      // M for motor
      // S for speed
      // Ex. M3S50 is motor 3 for 50 percent full speed

    // Controls:
      // pin_selects selects either motor or servo pins
      // pin_value has to be between 0-100 for motor pins (duty cycle value)
      // pin_value has to be between 0-180 for servo pins (angle value)

      


    // read incoming serial data:

    pin_select = Serial.parseInt(); // Reads first integer

    pin_value = Serial.parseInt(); // Reads second integer
   
  }
  
  switch (pin_select) {
    case 0:
      move_Motor();
      break;
    case 1:
      move_Motor();
      break;
    case 2:
      move_Servo();
      break;
  }
  
  Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\tY : ");
	Serial.print(mpu.getAngleY());
	Serial.print("\tZ : ");
	Serial.print(mpu.getAngleZ());

  Serial.print("\tCurrent Motor: ");
  Serial.print(pin_select);
  
  Serial.print("\tCurrent Speed (Duty Cycle) or Angle: ");
  Serial.println(pin_value);

  send_command();

  get_Angle();
 // moveMotor();
  //moveServo();
  


  }
