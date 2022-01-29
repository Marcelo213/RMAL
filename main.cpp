#include "Serial.h"

int main(void){

    std::string port = "/dev/ttyACM0";
    Serial arduino(port);
    
    std::string command = "Turn motor CW.";
    arduino.sendString(command);

	// Testing git

    std::cout << "Task complete." << std::endl;

    return 0;
}