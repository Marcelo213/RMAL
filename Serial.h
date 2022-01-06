#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <string>

// From Herk.hpp
static const uint8_t HERK_BUFFER = 223;  // maximum allowable packet size

class Serial{
    private:
        // Variables
        double something;
        
        // Necessary objects
        boost::asio::io_service io;
        //boost::asio::serial_port port(boost::asio::io_service io, std::string portName = "/dev/ttyUSB0");

        // From Herk.hpp
        boost::shared_ptr<boost::asio::serial_port>	_serial;

    public:
        Serial();
        ~Serial();

        // Setting Functions
        void s_default();
        bool s_portName(std::string port);
        bool s_baudRate(int rate);
        bool s_parity(int parity);
        bool s_stopBit(int bits);
        bool s_charSize(int size);

        // Doing Functions
        void sendString(std::string sendData);
        
        // Getting Functions
        std::string g_data();
};
