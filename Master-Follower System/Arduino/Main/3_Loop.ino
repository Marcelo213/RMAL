void loop(){

  /*if (Serial.available()) {      // If anything comes in Serial (USB),
    Serial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }*/
  /*if ((millis() - loop1Time100Hz) > 10) {
    loop1_100Hz();
    loop1Time100Hz = millis(); //Update timer
  }*/
  
  //read_encoder();
  if (Serial.available() > 0){
    
    motor_select = Serial.parseInt(); // Reads first integer
    motor_speed = Serial.parseInt();


    Serial.print("Motor Selected: ");
    Serial.print(motor_select);


    Serial.print("\tMotor Speed: ");
    Serial.println(motor_speed);
      switch (motor_select){
      case 0: // All motor stop
        motor_speed = 0;
        break;
      case 1: // Assist Assembly Linear Motor
        ASSIST_LINEAR_MOVE(motor_speed);
        break;
      case 2: // All motor stop
        ASSIST_ROTATION_MOVE(motor_speed);
        break;
      case 3: // All motor stop
        CATHETER_BENDING_MOVE(motor_speed);
        break;
      case 4:
        CATHETER_ROTATION_MOVE(motor_speed);
        break;
      case 5:
        ACTUATOR_MOVE(motor_speed);
        break;
      }
    

    }

    //Serial.println("Waiting for command....");



    
  }




/*void loop1_100Hz() {
  read_encoder();
}*/