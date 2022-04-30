#include "serial.h" 

Serial::Serial(){
  std::cout << "Connection established." << std::endl;
}

Serial::~Serial(){
  _serial->close();
}

// Setting Functions

bool Serial::s_portName(std::string port){
  _serial.reset(new boost::asio::serial_port(io));
  _serial->open(port);
  _serial->set_option(boost::asio::serial_port_base::baud_rate(115200));
  //_serial->set_option(boost::asio::de)
  return true;
}
bool Serial::s_baudRate(int rate){
  _serial->set_option(boost::asio::serial_port_base::baud_rate(rate));
  return true;
}

// Doing Functions
// - Need to give arduino time to load up
void Serial::sendString(std::string sendData){
  _serial->write_some(boost::asio::buffer(sendData.c_str(), sendData.size()));
}


//  Getting Functions
std::string Serial::g_data(){
  unsigned char out[HERK_BUFFER];
  _serial->read_some(boost::asio::buffer(out, HERK_BUFFER));
  std::string val(reinterpret_cast<char*> (out));

  return val;
}
  
  
  