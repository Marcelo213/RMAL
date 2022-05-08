#include <Servo.h>

Servo myServo;
float angle = 90;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(5);
myServo.write(90);
delay(5000);


}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0){
      String incomingByte = Serial.readStringUntil('\n');
        angle = incomingByte.toFloat();
        angle = angle * (180/3.14) + 90; // Angle in degrees
        
        myServo.write(angle);



        /*angle = 0.5 * (180/3.14) + 90; // Angle in degrees
        Serial.print("Arduino angle (in deg): ");
        Serial.println(angle);
        myServo.write(angle);*/

        
        
    }     //Serial.print("Arduino angle (in deg): ");
       Serial.println(angle);
        
}
