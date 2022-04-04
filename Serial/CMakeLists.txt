cmake_minimum_required(VERSION 3.10)


project(ArduinoDemo) # This is just a name for the project

add_library(LibsModule Serial.cpp) # This creates a library called 'LibsModule' that uses the definitions from Serial.cpp

target_link_libraries(LibsModule -lboost_system) # This links the libraries (the stuff after -l) to LibsModule
target_link_libraries(LibsModule -lboost_thread)
target_link_libraries(LibsModule -lpthread)

add_executable(main main.cpp) # This creates an executable called 'main' from the files of main.cpp

target_link_libraries(main LibsModule) # This links Libsmodule to the executable 'main'