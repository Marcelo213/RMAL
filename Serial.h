#ifndef SERIAL_H // Note: Is this way of naming identifiers in all caps a convention? Ask Taha
#define SERIAL_H

#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <stdlib.h>
#include <cstdlib>


class Serial{
    private:
        boost::asio::io_service io; 

    public:
        // Constructor for Serial Port
        Serial(std::string portName);
    
        // Doing Functions
        void sendString(std::string sendData);
        
};

#endif