void moveMotor(){
  
  Serial.print("Current Motor: ");
  Serial.print(motor_select);
  
  Serial.print("\tCurrent Speed (Duty Cycle): ");
  Serial.print(motor_speed);
  
  /*int potValue = analogRead(potPin);  
  Serial.print("\tADC analog value = ");
  Serial.print(potValue);
  */
  /*pwmValue = map(potValue, 0, 1023, 900, 2000);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.print("\tThe PWM value = ");
  Serial.println(pwmValue);
  */
  pwmValue = map(motor_speed, 0, 100, 900, 2000);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.print("\tThe PWM value = ");
  Serial.println(pwmValue);

  //motor_1.write(pwmValue);    // Send the signal to the ESC
  //pwm.setPWM(servonum, 2100, pwmValue);
  //pwm.writeMicroseconds(servonum, pwmValue);

  pwm.writeMicroseconds(motor_select, pwmValue);


}