cmake_minimum_required(VERSION 3.2)

project(DVS)

#Important CMAKE stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#VTK
set(VTK_DIR "C:/Users/marce/source/repos/vtk/build")        
find_package(VTK REQUIRED)
#include(${VTK_USE_FILE})
#include_directories(C:/Users/marce/source/repos/vtk/build)

#Eigen
find_package (Eigen3 REQUIRED NO_MODULE)
#find_package(C:Users/marce/Downloads/eigen-3.4.0/Eigen3)

#Dynamixel
#link_directories(/home/dvs/DynamixelSDK/c++/build/linux64)
#include_directories("/home/dvs/DynamixelSDK/c++/build/linux64")
#include_directories("/home/dvs/DynamixelSDK/c++/include/dynamixel_sdk")
#find_library(DynamixelSDK_LIB DynamixelSDK)

#include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})



#include source code
file(GLOB H_FILES ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(DVS main.cpp ${H_FILES} ${CPP_FILES})
target_link_libraries(DVS ${VTK_LIBRARIES} Eigen3::Eigen)
