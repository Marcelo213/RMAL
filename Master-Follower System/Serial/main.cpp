#include "Serial.h"

int main(void){

    std::string port = "/dev/ttyUSB0";
    Serial arduino(port);
    
    std::string command;

    std::cin >> command;
    arduino.sendString(command);

    std::cout << "Task complete." << std::endl;

    return 0;
}