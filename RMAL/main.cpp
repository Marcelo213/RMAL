#include "Serial.h"

int main(void){

    std::string port = "/dev/ttyACM0";
    Serial arduino(port);
    
    std::string command;

    std::cout << "Enter command: ";
    std::cin >> command;
    arduino.sendString(command);
    //arduino.g_data();

    return 0;

}