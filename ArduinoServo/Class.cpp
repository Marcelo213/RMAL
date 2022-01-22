#include "Class.h"
#include <Arduino.h>

Motor::Motor(int IN1, int IN2, int EN, int quadA, int quadB):
  IN1_(IN1), IN2_(IN2), EN_(EN), quadA_(quadA), quadB_(quadB)   {
  pinMode(IN1_,OUTPUT);
  pinMode(IN2_,OUTPUT);
  pinMode(EN_,OUTPUT);
  pinMode(quadA_,INPUT);
  pinMode(quadB_,INPUT);

  int statequadA_INI = digitalRead(quadA_);
}

void Motor::encoder(){
  
  int statequadA_ = digitalRead(quadA_);
  int statequadB_ = digitalRead(quadB_);
  
  if (statequadA_INI != statequadA_){
      if (statequadA_ != statequadB_){
       angle ++;
      } else  {
          angle --;
      }
      Serial.print("Position: ");
      Serial.println(angle);
    }
  statequadA_INI = statequadA_;
}
void Motor::moveCW( int distance ){
  
     int angle_init = angle + distance;
     
     digitalWrite(IN1_, LOW);
     digitalWrite(IN2_, HIGH);
     analogWrite(EN_, 50);
     
     while (angle <= angle_init){
        
        int statequadA_ = digitalRead(quadA_);
        int statequadB_ = digitalRead(quadB_);
  
        if (statequadA_INI != statequadA_){
             if (statequadA_ != statequadB_){
               angle ++;
             } else  {
             angle --;
                }
      //Serial.print("Position: ");
      Serial.println(angle);
    }
  statequadA_INI = statequadA_;
      }
        analogWrite(EN_, 0);
}
void Motor::moveCCW( int distance ){
  
     int angle_init = angle - distance;
     
     digitalWrite(IN1_, HIGH);
     digitalWrite(IN2_, LOW);
     analogWrite(EN_, 50);
     
     while (angle >= angle_init){
        
        int statequadA_ = digitalRead(quadA_);
        int statequadB_ = digitalRead(quadB_);
  
        if (statequadA_INI != statequadA_){
             if (statequadA_ != statequadB_){
               angle ++;
             } else  {
             angle --;
                }
      //Serial.print("Position: ");
      Serial.println(angle);
    }
  statequadA_INI = statequadA_;
      }
        analogWrite(EN_, 0);
}
void Motor::motorStop() {
     digitalWrite(IN1_, LOW);
     digitalWrite(IN2_, LOW);
     analogWrite(EN_, 0);
}
void Motor::rapidBlink(int pin){
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
