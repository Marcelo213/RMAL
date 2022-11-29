

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

    
    
    //Serial.print("A: ");
    //Serial.print(ASSIST_LINEAR_ENCODER_POSITION);
   // Serial.print("\tB: ");
    //Serial.print(ASSIST_ROTATION_ENCODER_POSITION);
    /*Serial.print("\tC  ");
    Serial.print(CATHETER_BENDING_ENCODER_POSITION);
    Serial.print("\tD ");
    Serial.println(CATHETER_ROTATION_ENCODER_POSITION);*/
    
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

    String linear_position_string = str.substring(str.indexOf('A') + 1, str.indexOf('B'));
    String theta_position_string = str.substring(str.indexOf('B') + 1, str.indexOf('C'));
    String phi_position_string = str.substring(str.indexOf('C') + 1, str.indexOf('S'));

    Target_Pose.x = linear_position_string.toDouble();
    Target_Pose.theta = theta_position_string.toDouble();
    Target_Pose.phi = phi_position_string.toDouble();

    } else if (start_char == 'I'){
    String motor_select_string = str.substring(str.indexOf('A') + 1, str.indexOf('B'));
    String rad_increment_string = str.substring(str.indexOf('B') + 1, str.indexOf('C'));

    motor_select = motor_select_string.toInt();
    rad_increment = rad_increment_string.toDouble();
      
    }
  }
  


}





/*
  Motor 1: 350 rating
  Motor 2: 350 rating
  Motor 3: 1000 rating
  Motor 4: 1000 rating
    
  Encoder value calculation
  Encoder pulse per revolution = 28
  so one rotation of output shaft = Encoder pulse per revolution X Gear Ratio
  So pulse per one rotation = 28 X 100
  = 2800 Pulse per revolution


  Note: By testing (not recorded), all the N20 motors used have a 28 encoder pulse count per revolution

  Pulse Per Revolution Values:
  Motor 1: 28 * 350 = 9800
  Motor 2: 28 * 300 = 8400
  Motor 3: 28 * 1000 = 28000
  Motor 4: 28 * 1000 = 28000
  Motor 5: -----> Is a stepper motor. TBD



  Note:            2*PI / 9800 = Radians per pulse

  PID Information Link: https://www.teachmemicro.com/arduino-pid-control-tutorial/#:~:text=To%20implement%20a%20PID%20controller,value%20and%20set%20point%20value.&text=1-,output%20%3D%20Kp%20*%20error%20%2B%20Ki%20*%20cumError%20%2B%20Kd%20*,Kd%20are%20the%20predetermined%20constants.
*/

// Returns the encoder count in rads
double get_rad_300(int encoder_count){
  double rad = ((2*PI) / 8400) * encoder_count;

  return rad;

}


double get_rad_1000(int encoder_count){
  double RAD_PER_ENCODER_COUNT_1000_RATING = 2*PI / 28000;
  double rad = RAD_PER_ENCODER_COUNT_1000_RATING * encoder_count;

  return rad;
}




/*
where  is  s the length of the arc, r  is the radius, and  theta is the measure of the angle in radians.

s = r*theta
s1 = s2
r1*theta1 = r2*theta*2
r1*theta1/r*2 = theta2 
14*theta1/50 = theta2

*/
double get_rad_convert_ASSIST_ASSEMBLY(double rad_in){
  // FOR ROTATION
  double rad = 14*rad_in/50;
  return rad;
}


double get_rad_convert_CATHETER_ASSEMBLY(double rad_in){
  // FOR ROTATION
  double rad = 22*rad_in/66;
  return rad;
}


// Converts theta change in rad to lienar change in mm
// This is done by comparing the change in angular position of wheel to angular position of motor

double get_linear_from_rad_350 (double rad){


}


