#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <string>



/**
 * @mainpage Serial Class 
 * @section Description
 *      This class allows communication with an object connected to a serial port.
 */


class Serial{
    private:
        
        // From Herk.hpp
        static const uint8_t m_bufferSize = 244;  // maximum allowable packet size

        // Necessary objects
        boost::asio::io_service m_IO;
    
        // From Herk.hpp
        boost::shared_ptr<boost::asio::serial_port>	m_Serial;

    

    public:
        /** 
         * @brief 
         *      Constructor is used to declare the serial port object.
         * @param[in] portName
         *      This is the name of the serial object, ex: "/dev/ttyUSB0" or "COM2"
         */
        Serial(std::string portName); // Constructor
        ~Serial(); // Deconstructor

        // Setting Functions - must return bool

        //void s_default();
        bool s_portName(std::string port);
        bool s_baudRate(int rate);
        bool s_parity(int parity);
        bool s_stopBit(int bits);
        bool s_charSize(int size);

        // Doing Functions - must return void

        /**
         * @brief 
         *      Sends a string to the serial object.
         * @param[in] sendData
         *      This is the string to be sent.
         */
        void sendString(std::string sendData);
        

        // Getting Functions - must return the expected output
        
        /**
         * @brief 
         *      Reads bytes from buffer. Must set buffer size.
         */
        void g_data();
        
};          
