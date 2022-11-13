void move_Servo () {

  pwmValue = map(pin_value, 0, 180, 600, 2400);   // scale it to use it with the servo library (value between 0 and 180)
  // The pin_value must be within 0-100 as a duty value percent; 600-2400 is the duration the wave is on in microseconds per 50 Hz

  pwm.writeMicroseconds(pin_select, pwmValue);

}