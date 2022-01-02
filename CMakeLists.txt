cmake_minimum_required(VERSION 3.10)


project(ArduinoDemo)

add_library(LibsModule Serial.cpp)

target_link_libraries(LibsModule -lboost_system)
target_link_libraries(LibsModule -lboost_thread)
target_link_libraries(LibsModule -lpthread)

add_executable(main main.cpp)

target_link_libraries(main LibsModule)
