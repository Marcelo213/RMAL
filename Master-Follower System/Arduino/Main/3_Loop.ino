void loop(){
 //read_encoder();
  // CATHETER_BENDING_CW(1500);

 // (1000);

  /*
  // CHANGING DIRECTION

  // LINEAR
  if (dir1c == 0) {             // Off; dir_c is a summation of the dir_a and dir_b 
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 1) {       // Left
    digitalWrite(dir1a, HIGH);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 2) {       // Right
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, HIGH);    
  }
  // BENDING
  if (dir2c == 0) {             // Off
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, LOW);
  } else if (dir2c == 1) {       // Left
    digitalWrite(dir2a, HIGH);
    digitalWrite(dir2b, LOW);    
  } else if (dir2c == 2) {       // Right
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, HIGH);    
  }
  // ROTATION
  if (dir3c == 0) {             // Off
    digitalWrite(dir3a, LOW);
    digitalWrite(dir3b, LOW);
  } else if (dir3c == 1) {       // Left
    digitalWrite(dir3a, HIGH);
    digitalWrite(dir3b, LOW);    
  } else if (dir3c == 2) {       // Right
    digitalWrite(dir3a, LOW);
    digitalWrite(dir3b, HIGH);    
  }
*/
/*
if (dir1c = 1){
  analogWrite(pwm1, speed1);
  delay(200);
}
else if (dir1c = 0){
  //analogWrite(pwm1, 0);
  delay(200);
}
  else if (dir1c = 2){
  analogWrite(pwm1, 2);
  delay(200);
  }
*/

  /*if (Serial.available()) {
    //  INCOMING TRANSMISSION
    String input = Serial.readString();
    char engage = input.charAt(0); // Security
    char terminate = input.charAt(4); // Security
    
    //  Example: M000S
    if ( (engage == 'M') && (terminate == 'S')) {
      
      dir1c = input.charAt(1) - '0';
      dir2c = input.charAt(2) - '0';
      dir3c = input.charAt(3) - '0';


  if (dir1c = 1){
      move1 = p1 - 10;
    } else if (dir1c = 2){
      move1 = p1 + 10;
    }
  if (dir2c = 1){
      move2 = p2 - 10;
    } else if (dir2c = 2){
      move2 = p2 + 10;
    }

    }}*/

    // OUTBOUND TRANSMISSION
    // STARTING TRANSMISSION COMMAND
    /*Serial.print("G");                    // Transmission start data preset in code book

    // TRANSLATION DATA
    //double op1 = abs((double(p3 + center3) / center3));
    double op1 = abs((double(p3) / center3)*100);
    int out_11 = op3 / 100;
    int out_12 = int(op3 / 10) % 10;
    int out_13 = int(op3) % 10;
    
    
    // BENDING DATA
    //double op1 = (double(abs(p1+center1)) / center1) * 180;  // Need to convert a series of numbers from -center>0>center into 0->360. So all I do is shift it, convert to deg
    double op1 = (double(abs(p1)) / center1) * 180;  // Need to convert a series of numbers from -center>0>center into 0->360. So all I do is shift it, convert to deg
    int out_11 = op1 / 100;               // Getting the 1st place value
    int out_12 = int(op1 / 10) % 10;      // Getting the 2nd place value
    int out_13 = int(op1) % 10;           // Getting the 3rd place value
    Serial.print(out_11);                 // Sending the 1st place value
    Serial.print(out_12);                 // Sending the 2nd place value
    Serial.print(out_13);                 // Sending the 3rd place value

    // ROTATION DATA
    double op2 = (double(p2 + center2) / center2) * 180;
    int out_21 = op2 / 100;
    int out_22 = int(op2 / 10) % 10;
    int out_23 = int(op2) % 10;
    Serial.print(out_21);                 // Sending the 1st place value
    Serial.print(out_22);                 // Sending the 2nd place value
    Serial.print(out_23);                 // Sending the 3rd place value



    // ENDING TRANSMISSION COMMAND
    Serial.println("SSS");              // Transmission end data preset in code book. (technically it is only one "S" but I send 3 just for filling the buffer. and forward compatability, in case we need to send more bytes
  }*/
}

