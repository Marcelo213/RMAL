#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS
// include OLED


// From Linear Actuator Code
#define STEPPIN 8
#define DIRPIN 9
#define ENAPIN 10

const int STEPTIME = 1000; // in microseconds; controls the speed of the linear actuator




//  PIN LABELS
char move1, move2, move3;

// LINEAR TRANSLATION
byte pos1 = 39;     // Encoder +5V        (pin)
byte enc1a = 48;    // Encoder A          (pin)
byte enclb = 49;    // Encoder B          (pin)
byte neg1 = 38;     // Encoder GND        (pin)
long p1 = 0;        // Encoder Current Position   (internal)
long np1O = 0;      // Encoder Previous Position  (internal)
int center1 = 40;  // Encoder Steps 180 deg      (internal)
byte pwm1 = 3;      // Motor PWM          (pin)
byte dir1a = 27;     // Motor Direction A  (pin)
byte dir1b = 26;     // Motor Direction B  (pin)
int state1 = 0;     // Motor State [dead, left, right, shake] (internal)
int dir1c = 0;      // Motor Direction                        (internal)
int speed1 = 100;     // Motor Speed [0, 30-100]                (internal)
Encoder en1(enc1a, enclb);  // Encoder Variable



// BENDING
byte pos2 = 37;     // Encoder +5V        (pin)
byte enc2a = 46;    // Encoder A          (pin)
byte enc2b = 47;    // Encoder B          (pin)
byte neg2 = 36;     // Encoder GND        (pin)
long p2 = 0;        // Encoder Current Position   (internal)
long np2O = 0;      // Encoder Previous Position  (internal)
int center2 = 1225;  // Encoder Steps 180 deg      (internal)
byte pwm2 = 4;      // Motor PWM          (pin)
byte dir2a = 25;     // Motor Direction A  (pin)
byte dir2b = 24;     // Motor Direction B  (pin)
int state2 = 0;     // Motor State [dead, left, right, shake] (internal)
int dir2c = 0;      // Motor Direction                        (internal)
int speed2 = 100;     // Motor Speed [0, 30-100]                (internal)
Encoder en2(enc2a, enc2b);  // Encoder Variable


// ROTATION
  byte pos3 = 35;     // Encoder +5V        (pin)
  byte enc3a = 44;    // Encoder A          (pin)
  byte enc3b = 45;    // Encoder B          (pin)
  byte neg3 = 34;     // Encoder GND        (pin)
  long p3 = 0;        // Encoder Current Position   (internal)
  long np3O = 0;      // Encoder Previous Position  (internal)
  int center3 = 1225;  // Encoder Steps 180 deg      (internal)
  byte pwm3 = 5;      // Motor PWM          (pin)
  byte dir3a = 23;     // Motor Direction A  (pin)
  byte dir3b = 22;     // Motor Direction B  (pin)
  int state3 = 0;     // Motor State [dead, left, right, shake] (internal)
  int dir3c = 0;      // Motor Direction                        (internal)
  int speed3 = 100;     // Motor Speed [0, 30-100]                (internal)
  Encoder en3(enc3a, enc3b);


void setup() {

   // Code from Linear Actuator
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT); // I disabled the code about the enable line because this code is using a TB6600 but we have a different IC


  
  Serial.begin(115200);
  Serial.println("Getting Started ");
  Serial.setTimeout(2);

  // PIN SETUP
  
  // LINEAR TRANSLATION
  pinMode(pos1, OUTPUT);
  pinMode(neg1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir1a, OUTPUT);
  pinMode(dir1b, OUTPUT);
  digitalWrite(pos1, HIGH);   // +5V
  digitalWrite(neg1, LOW);    // GND
  analogWrite(pwm1, 0);       // Always default to off state
  digitalWrite(dir1a, LOW);   // off state
  digitalWrite(dir1b, LOW);   // off state


  // BENDING
  pinMode(pos2, OUTPUT);
  pinMode(neg2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir2a, OUTPUT);
  pinMode(dir2b, OUTPUT);
  digitalWrite(pos2, HIGH);
  digitalWrite(neg2, LOW);
  analogWrite(pwm2, 0);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, LOW);

  
  // ROTATION
  pinMode(pos3, OUTPUT);
  pinMode(neg3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dir3a, OUTPUT);
  pinMode(dir3b, OUTPUT);
  digitalWrite(pos3, HIGH);
  digitalWrite(neg3, LOW);
  analogWrite(pwm3, 0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW);
  




  // TESTING MOVEMENT:

  delay(500); // This delay allows the system time to settle and to accurately execute commands 
  
  // Linear Actuator
 // linear_forward(500);
  //linear_backward(500);

  // Taut Mechanism
  //taut_forward(500);
  //taut_backward(500);
  
  // Bending
 // bending_cw(500);
  //bending_ccw(500); // There is currently no inputs to the bending function
  
  // Rotation
  //rotating_ccw(500); //parameter is in duration of microseconds
  rotating_cw(500);
}



void loop() {
 read_encoder();
  

/*
  // CHANGING DIRECTION

  // LINEAR
  if (dir1c == 0) {             // Off; dir_c is a summation of the dir_a and dir_b 
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 1) {       // Left
    digitalWrite(dir1a, HIGH);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 2) {       // Right
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, HIGH);    
  }
  // BENDING
  if (dir2c == 0) {             // Off
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, LOW);
  } else if (dir2c == 1) {       // Left
    digitalWrite(dir2a, HIGH);
    digitalWrite(dir2b, LOW);    
  } else if (dir2c == 2) {       // Right
    digitalWrite(dir2a, LOW);
    digitalWrite(dir2b, HIGH);    
  }
  // ROTATION
  if (dir3c == 0) {             // Off
    digitalWrite(dir3a, LOW);
    digitalWrite(dir3b, LOW);
  } else if (dir3c == 1) {       // Left
    digitalWrite(dir3a, HIGH);
    digitalWrite(dir3b, LOW);    
  } else if (dir3c == 2) {       // Right
    digitalWrite(dir3a, LOW);
    digitalWrite(dir3b, HIGH);    
  }
*/
/*
if (dir1c = 1){
  analogWrite(pwm1, speed1);
  delay(200);
}
else if (dir1c = 0){
  //analogWrite(pwm1, 0);
  delay(200);
}
  else if (dir1c = 2){
  analogWrite(pwm1, 2);
  delay(200);
  }
*/

  /*if (Serial.available()) {
    //  INCOMING TRANSMISSION
    String input = Serial.readString();
    char engage = input.charAt(0); // Security
    char terminate = input.charAt(4); // Security
    
    //  Example: M000S
    if ( (engage == 'M') && (terminate == 'S')) {
      
      dir1c = input.charAt(1) - '0';
      dir2c = input.charAt(2) - '0';
      dir3c = input.charAt(3) - '0';


  if (dir1c = 1){
      move1 = p1 - 10;
    } else if (dir1c = 2){
      move1 = p1 + 10;
    }
  if (dir2c = 1){
      move2 = p2 - 10;
    } else if (dir2c = 2){
      move2 = p2 + 10;
    }

    }}*/

    // OUTBOUND TRANSMISSION
    // STARTING TRANSMISSION COMMAND
    /*Serial.print("G");                    // Transmission start data preset in code book

    // TRANSLATION DATA
    //double op1 = abs((double(p3 + center3) / center3));
    double op1 = abs((double(p3) / center3)*100);
    int out_11 = op3 / 100;
    int out_12 = int(op3 / 10) % 10;
    int out_13 = int(op3) % 10;
    
    
    // BENDING DATA
    //double op1 = (double(abs(p1+center1)) / center1) * 180;  // Need to convert a series of numbers from -center>0>center into 0->360. So all I do is shift it, convert to deg
    double op1 = (double(abs(p1)) / center1) * 180;  // Need to convert a series of numbers from -center>0>center into 0->360. So all I do is shift it, convert to deg
    int out_11 = op1 / 100;               // Getting the 1st place value
    int out_12 = int(op1 / 10) % 10;      // Getting the 2nd place value
    int out_13 = int(op1) % 10;           // Getting the 3rd place value
    Serial.print(out_11);                 // Sending the 1st place value
    Serial.print(out_12);                 // Sending the 2nd place value
    Serial.print(out_13);                 // Sending the 3rd place value

    // ROTATION DATA
    double op2 = (double(p2 + center2) / center2) * 180;
    int out_21 = op2 / 100;
    int out_22 = int(op2 / 10) % 10;
    int out_23 = int(op2) % 10;
    Serial.print(out_21);                 // Sending the 1st place value
    Serial.print(out_22);                 // Sending the 2nd place value
    Serial.print(out_23);                 // Sending the 3rd place value



    // ENDING TRANSMISSION COMMAND
    Serial.println("SSS");              // Transmission end data preset in code book. (technically it is only one "S" but I send 3 just for filling the buffer. and forward compatability, in case we need to send more bytes
  }*/
}





void linear_forward(int steps){
  int i;
  digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
  digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delayMicroseconds(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delayMicroseconds(STEPTIME);
  }
  digitalWrite(ENAPIN,LOW);//DISABLE STEPPER


      /*// MOVING THE TAUT MECHANISM FORWARD
    analogWrite(pwm1, 100);       // Always default to off state
    digitalWrite(dir1a, HIGH);   // off state
    digitalWrite(dir1b, LOW);   // off state
*/
}

void linear_backward(int steps){
  int i;
  digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
  digitalWrite(DIRPIN,LOW);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delayMicroseconds(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delayMicroseconds(STEPTIME);
  }
  digitalWrite(ENAPIN,LOW);//DISABLE STEPPER
}


void read_encoder(){
  
  // READING ENCODERS: 
  // - LINEAR TRANSLATION
  long np1 = en1.read();
  if (np1 != np1O) {
    np1O = np1;
    p1 = np1;
    }

  // - BENDING
  long np2 = en2.read();
  if (np2 != np2O) {
    np2O = np2;
    p2 = np2;
    }

  // - ROTATION
    long np3 = en3.read();
    if (np3 != np3O) {
    np3O = np3;
    p3 = np3;
    }
Serial.print(p1);
Serial.print(" ");
Serial.print(p2);
Serial.print(" ");
Serial.println(p3);
}

void taut_forward(int duration){
  analogWrite(pwm1,150);
  digitalWrite(dir1a, HIGH);
  digitalWrite(dir1b, LOW); 
  delay(duration);
  analogWrite(pwm1,0);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, LOW);
}
void taut_backward(int duration){
  analogWrite(pwm1,100);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, HIGH); 
  delay(duration);
  analogWrite(pwm1,0);
  digitalWrite(dir1a, LOW);
  digitalWrite(dir1b, LOW);
}
void bending_cw(int duration){
  analogWrite(pwm2,100);
  digitalWrite(dir2a, HIGH);
  digitalWrite(dir2b, LOW); 
  delay(duration);
  analogWrite(pwm2,0);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, LOW);
}
void bending_ccw(int duration){
    analogWrite(pwm2,255);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, HIGH); 
  delay(duration);
  analogWrite(pwm2,0);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, LOW); 
}
void rotating_cw(int duration){
  analogWrite(pwm3,255);
  digitalWrite(dir3a, HIGH);
  digitalWrite(dir3b, LOW); 
  delay(duration);
  analogWrite(pwm3,0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW);
}
void rotating_ccw(int duration){
    analogWrite(pwm3,255);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, HIGH); 
  delay(duration);
  analogWrite(pwm3,0);
  digitalWrite(dir3a, LOW);
  digitalWrite(dir3b, LOW); 
}
