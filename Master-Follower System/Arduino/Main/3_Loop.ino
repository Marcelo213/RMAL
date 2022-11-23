void loop(){

  // ------- This creates a loop that has a frequency of 100Hz
 if ((millis() - loop1Time100Hz) > 10) {
    read_encoder();
    loop1Time100Hz = millis(); //Update timer
    //P_Controller();
  }
  P_Controller();

  //read_encoder();
  // ---------- The command is always being expected at the registered baud rate
  if (Serial.available() > 0){
    send_command();
  }
  

 
}