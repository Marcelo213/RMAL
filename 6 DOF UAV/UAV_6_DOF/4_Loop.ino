void loop() {

  if (Serial.available() > 0) {



      // M for motor
      // S for speed
      // Ex. M3S50 is motor 3 for 50 percent full speed

    // read incoming serial data:

    motor_select = Serial.parseInt(); // Reads first integer


    motor_speed = Serial.parseInt();
   
  
    
    Serial.println(motor_select);
  }
  

  // print out the values you read:
  /*int pin_state = digitalRead(SWITCH_PIN);
  if (pin_state == 0) {
    motor_select = 0;
  } else {
    motor_select = 15;
  }*/
  


  getAngle();
  moveMotor();

  


  }
