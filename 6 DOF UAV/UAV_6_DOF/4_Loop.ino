void loop() {

  /*if (Serial.available() > 0) {

    // read incoming serial data:
    motor_select = Serial.read();
    Serial.println(motor_select);

    // Type the next ASCII value from what you received:
    //Keyboard.write(inChar + 1);
  }*/
  

  // print out the values you read:
  int pin_state = digitalRead(SWITCH_PIN);
  if (pin_state == 0) {
    motor_select = 0;
  } else {
    motor_select = 15;
  }
  


  mpu.update();
  
  //if((millis()-timer)>10){ // print data every 10ms
	Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\tY : ");
	Serial.print(mpu.getAngleY());
	Serial.print("\tZ : ");
	Serial.print(mpu.getAngleZ());
	//timer = millis();  
  //}



  int potValue = analogRead(potPin);
  Serial.print("\tADC analog value = ");
  Serial.print(potValue);
  
  pwmValue = map(potValue, 0, 1023, 900, 2000);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.print("\tThe PWM value = ");
  Serial.println(pwmValue);

  //motor_1.write(pwmValue);    // Send the signal to the ESC
  //pwm.setPWM(servonum, 2100, pwmValue);
  //pwm.writeMicroseconds(servonum, pwmValue);

  pwm.writeMicroseconds(motor_select, pwmValue);



  }
