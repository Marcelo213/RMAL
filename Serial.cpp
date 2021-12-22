#include "Serial.h" // The header file we are declaring 

//Constructor
Serial::Serial(std::string portName){
    boost::asio::serial_port port(io, portName); // Creates serial_port object
}

//Sends string to arduino
void Serial::sendString(std::string sendData){

    port.write(sendData);
}
