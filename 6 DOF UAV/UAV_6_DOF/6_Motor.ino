void move_Motor(){
  
  
  

  pwmValue = map(pin_value, 0, 100, 900, 2000);   // scale it to use it with the servo library (value between 0 and 180)
  // The pin_value must be within 0-100 as a duty value percent; 900-2000 is the duration the wave is on in microseconds per 50 Hz

  pwm.writeMicroseconds(pin_select, pwmValue);


}