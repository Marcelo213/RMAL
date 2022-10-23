#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS

const int STEPTIME = 1000; // in microseconds; controls the speed of the linear actuator

//  PIN LABELS
char move1, move2, move3;

// LINEAR TRANSLATION
  long p1 = 0;        // Encoder Current Position   (internal)
  long np1O = 0;      // Encoder Previous Position  (internal)
  int center1 = 40;  // Encoder Steps 180 deg      (internal)
  int state1 = 0;     // Motor State [dead, left, right, shake] (internal)
  int dir1c = 0;      // Motor Direction                        (internal)
  int speed1 = 100;     // Motor Speed [0, 30-100]                (internal)
  Encoder en1(enc1a, enclb);  // Encoder Variable



// BENDING
  long p2 = 0;        // Encoder Current Position   (internal)
  long np2O = 0;      // Encoder Previous Position  (internal)
  int center2 = 1225;  // Encoder Steps 180 deg      (internal)
  int state2 = 0;     // Motor State [dead, left, right, shake] (internal)
  int dir2c = 0;      // Motor Direction                        (internal)
  int speed2 = 100;     // Motor Speed [0, 30-100]                (internal)
  Encoder en2(enc2a, enc2b);  // Encoder Variable


// ROTATION
  long p3 = 0;        // Encoder Current Position   (internal)
  long np3O = 0;      // Encoder Previous Position  (internal)
  int center3 = 1225;  // Encoder Steps 180 deg      (internal)
  int state3 = 0;     // Motor State [dead, left, right, shake] (internal)
  int dir3c = 0;      // Motor Direction                        (internal)
  int speed3 = 100;     // Motor Speed [0, 30-100]                (internal)
  Encoder en3(enc3a, enc3b);
