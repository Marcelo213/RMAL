
int quadratureA = 3;
int quadratureB = 4;
int buttonGreen = 6;  
int buttonBlack = 7;
int IN3 = 8;
int IN4 = 9;
int ENB = 10;
int angle = 0;
int stateQuadratureA_INI;
int stateQuadratureA;
int stateQuadratureB;

void setup () {
pinMode(buttonGreen, INPUT_PULLUP);
pinMode(buttonBlack, INPUT_PULLUP);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(quadratureA, INPUT);
pinMode(quadratureB, INPUT);
Serial.begin(9600); 
int stateQuadratureA_INI = digitalRead(quadratureA);
}

void loop () {
 int buttonStateGreen = digitalRead(buttonGreen);
 int buttonStateBlack = digitalRead(buttonBlack);
 
  if (buttonStateGreen == 0){
    Serial.println("Button Green is pressed.");
    delay(1000);
  } else if (buttonStateBlack == 0){
    Serial.println("Button Black is pressed.");
    delay(1000);
  } 
    if (Serial.available() > 0) {
      String incomingByte = Serial.readStringUntil('\n');
        if (incomingByte.equals("Turn motor CW.") == true) {
           rapidBlink(LED_BUILTIN);
           moveCW();
      } else if (incomingByte.equals("Turn motor CCW.") == true){
          rapidBlink(LED_BUILTIN);
           moveCCW();
        }
    } 
    encoder();
}


void encoder(){
int stateQuadratureA = digitalRead(quadratureA);
int stateQuadratureB = digitalRead(quadratureB);
  if (stateQuadratureA_INI != stateQuadratureA){
      if (stateQuadratureA != stateQuadratureB){
       angle ++;
      } else  {
      angle --;
      }
      Serial.print("Position: ");
      Serial.println(angle);
    }
    stateQuadratureA_INI = stateQuadratureA;
}
void rapidBlink(int pin) {
      digitalWrite(pin, HIGH); 
      delay(500);     
      digitalWrite(pin, LOW); 
      delay(500);  
      digitalWrite(pin, HIGH); 
      delay(500);  
      digitalWrite(pin, LOW); 
      delay(500); 
      digitalWrite(pin, HIGH); 
      delay(500);
} 
void moveCW(){
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 50);
      delay(1000);
      analogWrite(ENB, 0);
}
void moveCCW(){
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 50);
      delay(100);
      analogWrite(ENB, 0);
}
