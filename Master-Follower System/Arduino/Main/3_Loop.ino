void loop(){

  read_encoder();

  //  Format is A_B_C_D_          _ means duration in +/- direction


  // 

  if (Serial.available() > 0){
   
      // Define 
    String str = Serial.readString();
    
    // Length (with one extra character for the null terminator)
    int str_len = str.length() + 1; 

    // Prepare the character array (the buffer) 
    char char_array[str_len];

    // Copy it over 
    str.toCharArray(char_array, str_len);

  
    
    /*  NOTE: The motors are named as follows:
      Motor 1 = Assist Linear Motor
      Motor 2 = Assist Rotation Motor
      Motor 3 = Catheter Bending Motor
      Motor 4 = Catheter Rotation Motor
      Motor 5 = Linear Actuator


    */



    
    
    for(int i =0; i < str_len; i++ ) {

      // Confirms if the serial message is a command
        char start_char = char_array[i];
        if (start_char == 'A') {
        Serial.println("Made it!");

        String motor_1_speed_string = str.substring(str.indexOf('A') + 1, str.indexOf('B'));
        String motor_2_speed_string = str.substring(str.indexOf('B') + 1, str.indexOf('C'));
        String motor_3_speed_string = str.substring(str.indexOf('C') + 1, str.indexOf('D'));
        String motor_4_speed_string = str.substring(str.indexOf('D') + 1, str.indexOf('E'));
        String motor_5_speed_string = str.substring(str.indexOf('E') + 1, str.indexOf('S'));

        int motor_1_speed_int = motor_1_speed_string.toInt();
        int motor_2_speed_int = motor_2_speed_string.toInt();
        int motor_3_speed_int = motor_3_speed_string.toInt();
        int motor_4_speed_int = motor_4_speed_string.toInt();
        int motor_5_speed_int = motor_5_speed_string.toInt();
      

        // Test Command: A1B2C3D4E5S


        Serial.println(motor_1_speed_int);
        Serial.println(motor_2_speed_int);
        Serial.println(motor_3_speed_int);
        Serial.println(motor_4_speed_int);
        Serial.println(motor_5_speed_int);
        Serial.println(" ");

        //ASSIST_LINEAR_MOVE(motor_1_speed_int);
        ASSIST_LINEAR_MOVE_THETA(motor_1_speed_int);
        ASSIST_ROTATION_MOVE(motor_2_speed_int);
        CATHETER_BENDING_MOVE(motor_3_speed_int);
        CATHETER_ROTATION_MOVE(motor_4_speed_int);
        ACTUATOR_MOVE(motor_5_speed_int);


        motor_1_speed_int = 0;
        motor_2_speed_int = 0;
        motor_3_speed_int = 0;
        motor_4_speed_int = 0;
        motor_5_speed_int = 0;
      

        }
    }
    





    
  }
   //Serial.println("Waiting...");
   /* motor_select = Serial.parseInt(); // Reads first integer
    motor_speed = Serial.parseInt();


    Serial.print("Motor Selected: ");
    Serial.print(motor_select);


    Serial.print("\tMotor Speed: ");
    Serial.println(motor_speed);
    */

/*
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

*/

    
  }




/*void loop1_100Hz() {
  read_encoder();
}*/