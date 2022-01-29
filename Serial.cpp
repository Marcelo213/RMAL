#include "Serial.h" 

Serial::Serial(std::string portName){
  // From Herk.cpp ; Constructor acts as default
  m_Serial.reset(new boost::asio::serial_port(m_IO));
  m_Serial->open(portName);
  m_Serial->set_option(boost::asio::serial_port_base::baud_rate(9600));

  boost::asio::deadline_timer t(m_IO, boost::posix_time::seconds(5));
  t.wait(); // NOTE: Put the delay in the setup, this way the arduino prepares and our further communcation is faster

  std::cout << "Connection established." << std::endl;
}

Serial::~Serial(){
  m_Serial->close();
}

// Setting Functions
/*void Serial::s_default(){};

bool Serial::s_portName(std::string port){
  m_Serial->open(port);
  return true;
}

bool Serial::s_baudRate(int rate){
  m_Serial->set_option(boost::asio::serial_port_base::baud_rate(rate));
  return true;
}*/

/*bool Serial::s_parity(int parity){}
bool Serial::s_stopBit(int bits){}
bool Serial::s_charSize(int size){}*/


// Doing Functions
// - Need to give arduino time to load up
void Serial::sendString(std::string sendData){
  m_Serial->write_some(boost::asio::buffer(sendData.c_str(), sendData.size()));

  boost::asio::deadline_timer t(m_IO, boost::posix_time::seconds(5));
  t.wait();



  unsigned char out[m_bufferSize];
  m_Serial->read_some(boost::asio::buffer(out, m_bufferSize));
  std::string val(reinterpret_cast<char*> (out));
  
  /*char delimiter('\n');
  int pos = val.find(delimiter);
  pos += 1;
  std::string command = val.substr(0,pos);
  std::cout << command << std:: endl;*/
  
  std::cout << val << std:: endl;
  



}


//  Getting Functions
void Serial::g_data(){
  unsigned char out[m_bufferSize];
  m_Serial->read_some(boost::asio::buffer(out, m_bufferSize));
  std::string val(reinterpret_cast<char*> (out));
  //char delimiter('.');
  //int pos = val.find(delimiter);
  //pos += 1;
  //std::string command = val.substr(0,pos);
  
  std::cout << "Got here1 \n";
  //std::cout << command << std:: endl;
  std::cout << val << std:: endl;
  std::cout << "Got here2 \n";
  
  
  
  
}
