#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(5);
myServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0){
      String incomingByte = Serial.readStringUntil('\n');
        if (incomingByte.equals("Left") == true ){
          myServo.write(0);
        } else if (incomingByte.equals("Right") == true){
          myServo.write(180);
        } 
        
    }     delay(1000);
        myServo.write(90);
}
