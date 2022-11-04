#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS

const int STEPTIME = 1000; // in microseconds; controls the speed of the linear actuator

//  PIN LABELS
// char move1, move2, move3;

// CATHETER ASSEMBLY
  // BENDING
    long p2 = 0;             // Encoder Current Position   (internal)
    long np2O = 0;           // Encoder Previous Position  (internal)
    int center2 = 1225;      // Encoder Steps 180 deg      (internal)
    int state2 = 0;          // Motor State [dead, left, right, shake] (internal)
    int dir2c = 0;           // Motor Direction                        (internal)
    int speed2 = 100;        // Motor Speed [0, 30-100]                (internal)
    Encoder CATHETER_BENDING_ENCODER(CATHETER_BENDING_ENCODER_A_PIN, CATHETER_BENDING_ENCODER_B_PIN);  // Encoder Variable
  //
  // ROTATION
    long p4 = 0;             // Encoder Current Position   (internal)
    long np4O = 0;           // Encoder Previous Position  (internal)
    int center4 = 1225;      // Encoder Steps 180 deg      (internal)
    int state4 = 0;          // Motor State [dead, left, right, shake] (internal)
    int dir4c = 0;           // Motor Direction                        (internal)
    int speed4 = 100;        // Motor Speed [0, 30-100]                (internal)
    Encoder CATHETER_ROTATION_ENCODER(CATHETER_ROTATION_ENCODER_A_PIN, CATHETER_ROTATION_ENCODER_B_PIN);
//

// ASSIST ASSEMBLY

  // LINEAR TRANSLATION
    long p1 = 0;          // Encoder Current Position   (internal)
    long np1O = 0;        // Encoder Previous Position  (internal)
    int center1 = 40;     // Encoder Steps 180 deg      (internal)
    int state1 = 0;       // Motor State [dead, left, right, shake] (internal)
    int dir1c = 0;        // Motor Direction                        (internal)
    int speed1 = 100;     // Motor Speed [0, 30-100]                (internal)
    Encoder ASSIST_LINEAR_ENCODER(ASSIST_LINEAR_ENCODER_A_PIN, ASSIST_LINEAR_ENCODER_B_PIN);  // Encoder Variable
  //

  // ROTATION
    long p3 = 0;            // Encoder Current Position   (internal)
    long np3O = 0;          // Encoder Previous Position  (internal)
    int center3 = 1225;     // Encoder Steps 180 deg      (internal)
    int state3 = 0;         // Motor State [dead, left, right, shake] (internal)
    int dir3c = 0;          // Motor Direction                        (internal)
    int speed3 = 100;       // Motor Speed [0, 30-100]                (internal)
    Encoder ASSIST_ROTATION_ENCODER(ASSIST_ROTATION_ENCODER_A_PIN, ASSIST_ROTATION_ENCODER_B_PIN);  // Encoder Variable
  //

//

uint64_t loop1Time100Hz = 0;
long ASSIST_LINEAR_ENCODER_POSITION = 0;
long ASSIST_ROTATION_ENCODER_POSITION = 0;
long CATHETER_BENDING_ENCODER_POSITION = 0;
long CATHETER_ROTATION_ENCODER_POSITION = 0;