#pragma once 

class Motor { 
  public:
    Motor(int IN1, int IN2, int EN, int quadA, int quadB);
    void encoder();
    void moveCW(int distance);
    void moveCCW(int distance);
    void rapidBlink(int pin);
    void motorStop();
    
  private:
    int IN1_;
    int IN2_;
    int EN_;
    int quadA_;
    int quadB_;
    int angle = 0;
    int statequadA_INI;
};
