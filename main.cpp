#include "Serial.h"

std::string portName = "/dev/ttyUSB0";
std::string command = "on";

int main(void){

    Serial arduino(portName);
    //arduino.s_default();
    arduino.sendString(command);

    return 0;

    }