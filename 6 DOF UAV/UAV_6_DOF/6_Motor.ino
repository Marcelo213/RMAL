


/*
#include <ESP32Servo.h>
 
Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32
 
 int potValue;  // value from the analog pin
 int analogValue;
 
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 25;
int potPin = 34;



void setup() {
  Serial.begin(115200);
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}

void loop() {
  // print out the values you read:
  int analogValue = analogRead(potPin);
  Serial.printf("ADC analog value = %d\n",analogValue);
  potValue = map(analogValue, 0, 4095, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.printf("The PWM value = %d\n",potValue);
  
  myservo.write(potValue);    // Send the signal to the ESC
  //delay(100);  // delay in between reads for clear read from serial

  
}*/