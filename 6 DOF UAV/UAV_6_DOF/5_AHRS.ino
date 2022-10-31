void getAngle() {

  
  mpu.update();
  
  //if((millis()-timer)>10){ // print data every 10ms
	Serial.print("X : ");
	Serial.print(mpu.getAngleX());
	Serial.print("\tY : ");
	Serial.print(mpu.getAngleY());
	Serial.print("\tZ : ");
	Serial.print(mpu.getAngleZ());
	//timer = millis();  
  //}
}