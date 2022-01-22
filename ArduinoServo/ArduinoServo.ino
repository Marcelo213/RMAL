#include "Class.h"

// Motor(int IN1, int IN2, int EN, int quadA, int quadB):
Motor servo1(5,6,7,A14,A15);
Motor servo2(8, 9, 10, A12, A13);
Motor servo3(11, 12, 13, A10, A11);

void setup () {
Serial.begin(9600); 
servo1.rapidBlink(LED_BUILTIN);
//servo1.moveCCW(5);
//servo2.moveCCW(50);
//servo3.moveCW(50);
//servo3.encoder();
//servo2.encoder();

}

void loop () {

  //servo1.encoder();
  //servo2.encoder();
  //servo3.encoder();
  
    if (Serial.available() > 0) {
      String incomingByte = Serial.readStringUntil('\n');
        if (incomingByte.equals("Turn motor CW.") == true) {
           //servo1.rapidBlink(LED_BUILTIN);
           servo1.moveCW(20);
           //servo2.moveCW(20);
           //servo3.moveCW(20);
           
      } else if (incomingByte.equals("Turn motor CCW.") == true){
           //servo1.rapidBlink(LED_BUILTIN);
           servo1.moveCCW(20);
           //servo2.moveCCW(20);
           //servo3.moveCCW(5);
        }
    } servo1.motorStop();
}
