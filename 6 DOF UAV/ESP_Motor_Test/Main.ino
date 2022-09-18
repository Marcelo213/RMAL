/*// the number of the LED pin
const int ledPin = 26;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 50;
const int ledChannel = 0;
const int resolution = 12;
 
//////////////
#include <Servo.h>

Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin


void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);


////////////
  // configure LED PWM functionalitites
  //ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  //ledcAttachPin(ledPin, ledChannel);
  //////////////////
    // Attach the ESC on pin 9
  ESC.attach(26,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
}

void loop() {
  // read the analog / millivolts value for pin 2:
  int analogValue = analogRead(34);
  
  // print out the values you read:
  Serial.printf("ADC analog value = %d\n",analogValue);
  
  delay(100);  // delay in between reads for clear read from serial


////////////


  //potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(analogValue, 0, 4095, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.printf("The PWM value = %d\n",potValue);
  ledcWrite(ledChannel, potValue); 
  //ESC.write(potValue);    // Send the signal to the ESC


  
}*/
