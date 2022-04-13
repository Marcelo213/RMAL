#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS

// PIN LABELS
// BENDING
byte pos1 = A3;     // Encoder +5V        (pin)
byte enc1a = A1;    // Encoder A          (pin)
byte enclb = A2;    // Encoder B          (pin)
byte neg1 = A0;     // Encoder GND        (pin)
long p1 = 0;        // Encoder Current Position   (internal)
long np1O = 0;      // Encoder Previous Position  (internal)
int center1 = 40;  // Encoder Steps 180 deg      (internal)
byte pwm1 = 2;      // Motor PWM          (pin)
byte dir1a = 3;     // Motor Direction A  (pin)
byte dir1b = 4;     // Motor Direction B  (pin)
int state1 = 0;     // Motor State [dead, left, right, shake] (internal)
int dir1c = 0;      // Motor Direction                        (internal)
int speed1 = 0;     // Motor Speed [0, 30-100]                (internal)
Encoder en1(enc1a, enclb);  // Encoder Variable

// ROTATIONp1
byte pos2 = A4;     // Encoder +5V        (pin)
byte enc2a = A5;    // Encoder A          (pin)
byte enc2b = A6;    // Encoder B          (pin)
byte neg2 = A7;     // Encoder GND        (pin)
long p2 = 0;        // Encoder Current Position   (internal)
long np2O = 0;      // Encoder Previous Position  (internal)
int center2 = 1225;  // Encoder Steps 180 deg      (internal)
byte pwm2 = 5;      // Motor PWM          (pin)
byte dir2a = 6;     // Motor Direction A  (pin)
byte dir2b = 7;     // Motor Direction B  (pin)
int state2 = 0;     // Motor State [dead, left, right, shake] (internal)
int dir2c = 0;      // Motor Direction                        (internal)
int speed2 = 0;     // Motor Speed [0, 30-100]                (internal)
Encoder en2(enc2a, enc2b);  // Encoder Variable


//byte enc2a = 5;  // Rotation
//byte enc2b = 6;
byte pos3 = A11;     // Encoder +5V        (pin)
byte enc3a = A9;    // Encoder A          (pin)
byte enc3b = A10;    // Encoder B          (pin)
byte neg3 = A8;     // Encoder GND        (pin)
long p3 = 0;        // Encoder Current Position   (internal)
long np3O = 0;      // Encoder Previous Position  (internal)
int center3 = 1225;  // Encoder Steps 180 deg      (internal)
byte pwm3 = 5;      // Motor PWM          (pin)
//byte dir3a = 6;     // Motor Direction A  (pin)
//byte dir3b = 7;     // Motor Direction B  (pin)
int state3 = 0;     // Motor State [dead, left, right, shake] (internal)
int dir3c = 0;      // Motor Direction                        (internal)
int speed3 = 0;     // Motor Speed [0, 30-100]                (internal)
Encoder en3(enc3a, enc3b);

void setup() {
  Serial.begin(115200);
  Serial.println("Getting Started ");
  Serial.setTimeout(2);

  // PIN SETUP
  // BENDING
  pinMode(pos1, OUTPUT);
  pinMode(neg1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir1a, OUTPUT);
  pinMode(dir1b, OUTPUT);
  digitalWrite(pos1, HIGH);   // +5V
  digitalWrite(neg1, LOW);    // GND
  analogWrite(pwm1, 50);       // Always default to off state
  digitalWrite(dir1a, LOW);   // off state
  digitalWrite(dir1b, LOW);   // off state
  // ROTATION
  pinMode(pos2, OUTPUT);
  pinMode(neg2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir2a, OUTPUT);
  pinMode(dir2b, OUTPUT);
  digitalWrite(pos2, HIGH);
  digitalWrite(neg2, LOW);
  analogWrite(pwm2, 50);
  digitalWrite(dir2a, LOW);
  digitalWrite(dir2b, LOW);

  // TRANSLATION
  pinMode(pos3, OUTPUT);
  pinMode(neg3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  //pinMode(dir3a, OUTPUT);
  //pinMode(dir3b, OUTPUT);
  digitalWrite(pos3, HIGH);
  digitalWrite(neg3, LOW);
  //analogWrite(pwm1, 0);
  //digitalWrite(dir1a, LOW);
  //digitalWrite(dir1b, LOW);
}


void loop() {

  // READING ENCODER
  // BENDING
  long np1 = en1.read();
  if (np1 != np1O) {
    np1O = np1;
    p1 = np1;
  }
  // ROTATION
  long np2 = en2.read();
  if (np2 != np2O) {
    np2O = np2;
    p2 = np2;
  }
  // TRANSLATION
  long np3 = en3.read();
  if (np3 != np3O) {
    np3O = np3;
    p3 = np3;
  }

  // CHANGING MOTOR STATE
  // BENDING
  if (state1 == 0) {        // Setting off
    dir1c = 0;
  } else if (state1 == 1) {  // Setting Left
    dir1c = 1;
  } else if (state1 == 2) {  // Setting Right
    dir1c = 2;
  } else if (state1 == 3) {  // Setting Shake
    if (dir1c == 1) {         // If was left now right
      dir1c = 2;
    } else {                  // If was not left now left.
      dir1c = 1;
    }
    //Serial.println(dir1c);
  } 
  else if (state2 == 0) {        // Setting off
    dir2c = 0;
  } else if (state2 == 1) {  // Setting Left
    dir2c = 1;
  } else if (state2 == 2) {  // Setting Right
    dir2c = 2;
  } else if (state2 == 3) {  // Setting Shake
    if (dir2c == 1) {         // If was left now right
      dir2c = 2;
    } else {                  // If was not left now left.
      dir2c = 1;
    }
    Serial.println(dir2c);
  }

  // CHANGING DIRECTION
  // BENDING
  if (dir1c == 0) {             // Off
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 1) {       // Left
    digitalWrite(dir1a, HIGH);
    digitalWrite(dir1b, LOW);
  } else if (dir1c == 2) {       // Right
    digitalWrite(dir1a, LOW);
    digitalWrite(dir1b, HIGH);
  }
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

  // CHANGING SPEED
  analogWrite(pwm1, speed1);
  analogWrite(pwm2, speed2);

  if (Serial.available()) {
    // INCOMING TRANSMISSION
    //byte inByte = Serial.read();          // Reading data from the controller. (Depending on what it is actions will be taken)
    String data = Serial.readString();
    char engage = data.charAt(0);
    char terminate = data.charAt(7);
    //M000000S
    if ( (engage == 'M') && (terminate == 'S')) {
      state1 = data.charAt(1)-'0';
      state2 = data.charAt(2)-'0';
      //state3 = data.charAt(3);
      speed1 = (data.charAt(4)-'0')*10;
      speed2 = (data.charAt(5)-'0')*10;
      Serial.println(state1); 
      Serial.println(state2); 
      Serial.println(speed1);
      Serial.println(speed2);
      //speed3 = data.charAt(6);
      //char engage = data.charAt(7);
      
    }

    // OUTBOUND TRANSMISSION
    // STARTING TRANSMISSION COMMAND
    Serial.print("G");                    // Transmission start data preset in code book
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
    Serial.print(out_21);
    Serial.print(out_22);
    Serial.print(out_23); 
    // TRANSLATION DATA
    //double op3 = abs((double(p3 + center3) / center3));
    double op3 = abs((double(p3) / center3)*100);
    int out_31 = op3 / 100;
    int out_32 = int(op3 / 10) % 10;
    int out_33 = int(op3) % 10;
    Serial.print(out_31);
    Serial.print(out_32);
    Serial.print(out_33);
    // ENDING TRANSMISSION COMMAND
    Serial.println("SSS");              // Transmission end data preset in code book. (technically it is only one "S" but I send 3 just for filling the buffer. and forward compatability, in case we need to send more bytes
  }
}
