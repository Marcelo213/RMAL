//Globals
// Need to change this pins wrt the setup
#define STEPPIN 3
#define DIRPIN 2
#define ENAPIN 10

const int STEPTIME = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT); // I disabled the code about the enable line because this code is using a TB6600 but we have a different IC
  forward(800);
  reverse(8 00);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void forward(int steps){
  int i;
  //digitalWrite(ENAPIN,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delay(STEPTIME);
  }
 // digitalWrite(ENAPIN,HIGH);//DISABLE STEPPER
}

void reverse(int steps){
  int i;
  //digitalWrite(ENAPIN,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN,LOW);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delay(STEPTIME);
  }
  //digitalWrite(ENAPIN,HIGH);//DISABLE STEPPER
}
