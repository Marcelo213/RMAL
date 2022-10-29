void loop() {

  if (Serial.available() > 0) {

    // read incoming serial data:
    motor_select = Serial.read();
    Serial.println(motor_select);

    // Type the next ASCII value from what you received:
    //Keyboard.write(inChar + 1);
  }
  

  // print out the values you read:


  int potValue = analogRead(potPin);
  //Serial.print("ADC analog value = ");
  //Serial.print(potValue);
  
  pwmValue = map(potValue, 0, 1023, 900, 2000);   // scale it to use it with the servo library (value between 0 and 180)
 // Serial.print("     The PWM value = ");
 // Serial.println(pwmValue);

  //motor_1.write(pwmValue);    // Send the signal to the ESC

  //pwm.setPWM(servonum, 2100, pwmValue);
  //pwm.writeMicroseconds(servonum, pwmValue);
  pwm.writeMicroseconds(15, pwmValue);
  }
