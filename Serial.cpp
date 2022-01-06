#include "Serial.h" // The header file we are declaring 

Serial::Serial(){
  // From Herk.cpp ; Constructor acts as default
  _serial.reset(new boost::asio::serial_port(io));
  std::string portName = "/dev/ttyUSB1";
  _serial->open(portName);
  _serial->set_option(boost::asio::serial_port_base::baud_rate(9600));
}

Serial::~Serial(){
  _serial->close();
}

// Setting Functions
/*void Serial::s_default(){};

bool Serial::s_portName(std::string port){
  _serial->open(port);
  return true;
}

bool Serial::s_baudRate(int rate){
  _serial->set_option(boost::asio::serial_port_base::baud_rate(rate));
  return true;
}*/

/*bool Serial::s_parity(int parity){}
bool Serial::s_stopBit(int bits){}
bool Serial::s_charSize(int size){}*/


// Doing Functions
// - Need to give arduino time to load up
void Serial::sendString(std::string sendData){
  boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
  t.wait();
  _serial->write_some(boost::asio::buffer(sendData.c_str(), sendData.size()));
}


//  Getting Functions
//std::string Serial::g_data(){}
