

// -------- Processes the counts for the encoders for all motors except the linear actuator
void read_encoder(){
  // READING ENCODERS: 
    // - LINEAR TRANSLATION
    long np1 = ASSIST_LINEAR_ENCODER.read();
    if (np1 != np1O) {
      np1O = np1;
      p1 = np1;
      }

    // - BENDING
    long np2 = CATHETER_BENDING_ENCODER.read();
    if (np2 != np2O) {
      np2O = np2;
      p2 = np2;
      }

    // - ROTATION
      long np3 = ASSIST_ROTATION_ENCODER.read();
      if (np3 != np3O) {
      np3O = np3;
      p3 = np3;
      }

      // - ROTATION
      long np4 = CATHETER_ROTATION_ENCODER.read();
      if (np4 != np4O) {
      np4O = np4;
      p4 = np4;
      }

    
  ASSIST_LINEAR_ENCODER_POSITION = p1;
  ASSIST_ROTATION_ENCODER_POSITION = p3;
  CATHETER_BENDING_ENCODER_POSITION = p2;
  CATHETER_ROTATION_ENCODER_POSITION = p4;

  
    
    Serial.print("A: ");
    Serial.print(ASSIST_LINEAR_ENCODER_POSITION);
    Serial.print("\tB: ");
    Serial.print(ASSIST_ROTATION_ENCODER_POSITION);
    Serial.print("\tC  ");
    Serial.print(CATHETER_BENDING_ENCODER_POSITION);
    Serial.print("\tD ");
    Serial.println(CATHETER_ROTATION_ENCODER_POSITION);
    
}

// ------ For communication with the serial port to send commands to motors simultaneously
//                   Format is A_B_C_D_S         Place the direction in means duration in +/- direction
void send_command(){

   
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

        Motor_1_Theta_Rad = motor_1_speed_string.toDouble();
        Motor_2_Theta_Rad = motor_2_speed_string.toDouble();
        Motor_3_Theta_Rad = motor_3_speed_string.toDouble();
        Motor_4_Theta_Rad = motor_4_speed_string.toDouble();
        Motor_5_Theta_Rad = motor_5_speed_string.toDouble();
        
      

        

     

      

        }
    }
    


}



