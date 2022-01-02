#include "Serial.h" // The header file we are declaring 

Serial::Serial(){}
Serial::~Serial(){}

boost::asio::io_service io;
boost::asio::serial_port port(boost::asio::io_service io, std::string portName = "/dev/ttyUSB0");


void Serial::sendString(std::string sendData){
  port.write_some(boost::asio::buffer(sendData.c_str(), sendData.size()) )
}


