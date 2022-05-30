#include "Class.h"

//Motor(int IN1, int IN2, int EN, int quadA, int quadB):
Motor servo1(5, 4, 3, A2, A3);
Motor servo2(11, 10, 9, A4, A5);
//Motor servo3(11, 12, 13, A10, A11);

void setup () {
Serial.begin(9600); 
servo2.rapidBlink(LED_BUILTIN);
 //servo2.moveCW(20);
//servo1.moveCCW(5);
//servo2.moveCCW(50);
//servo3.moveCW(50);
//servo3.encoder();
//servo2.encoder();

}

void loop () {

  servo1.encoder();
  //servo1.moveCW(20);
  //servo2.moveCW(20);
  servo2.encoder();
  //servo3.encoder();
  
    if (Serial.available() > 0) {
     // Serial.println("Test");
      String incomingByte = Serial.readStringUntil('\n');
        if (incomingByte.equals("Turn motor CW.") == true) {
           //servo1.rapidBlink(LED_BUILTIN);
           servo2.moveCW(20);
           //servo2.moveCW(20);
           //servo3.moveCW(20);
           
      } else if (incomingByte.equals("Turn motor CCW.") == true){
           //servo1.rapidBlink(LED_BUILTIN);
           servo2.moveCCW(20);
           //servo2.moveCCW(20);
           //servo3.moveCCW(5);
        }
    } servo2.motorStop();
}
