void loop(){

  if (Serial.available()) {      // If anything comes in Serial (USB),
    Serial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }
 /* if ((millis() - loop1Time100Hz) > 10) {
    loop1_100Hz();
    loop1Time100Hz = millis(); //Update timer
    //Serial.print("HERE");
  }
  if (Serial.available() > 0){
    //sSerial.flush();
    char command = Serial.read();
      Serial.print("The command was: ");
      Serial.println(command);
    if (command == "g"){
      Serial.print("HERE");
      Serial.print("The command was: ");
      Serial.println(command);
      //CATHETER_ROTATING_CW(50);
    }
  }*/
}
/*
void loop1_100Hz() {
  // Update ENCODER COUNT and POSE
  read_encoder();

/*/