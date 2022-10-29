void loop() {
  // print out the values you read:
  int potValue = analogRead(potPin);
  Serial.print("ADC analog value = ");
  Serial.print(potValue);
  
  pwmValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.print("     The PWM value = ");
  Serial.println(pwmValue);

  motor_1.write(pwmValue);    // Send the signal to the ESC

  
}