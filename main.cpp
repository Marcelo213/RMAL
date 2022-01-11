#include "Serial.h"




int main(void){

    //      Note: Libraries must be linked.
    //      Use g++ main.cpp -o main -L /usr/lib/ -lboost_system -lboost_thread -lpthread
    //      Boost library and Thread library must be used

    Serial arduino;
    
    arduino.g_data();
    
    
    
    return 0;

}
