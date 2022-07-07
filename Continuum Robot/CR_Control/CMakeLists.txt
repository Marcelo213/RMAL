cmake_minimum_required(VERSION 3.2)

#Creates CMake Project
project(DVS)

#Important CMAKE stuff
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#VTK
set(VTK_DIR "~/Downloads/VTK-9.2.0.rc1/build/")      
find_package(VTK REQUIRED)

#Eigen
find_package (Eigen3 REQUIRED NO_MODULE)

#ROS
set(roscpp_DIR "/etc/apt")
find_package(catkin REQUIRED COMPONENTS
    roscpp
)

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES ${PROJECT_NAME}
   CATKIN_DEPENDS roscpp
 )
include_directories(include ${PROJECT_SOURCE_DIR} ${catkin_INCLUDE_DIRS})
#link_directories(/var/cache/apt/archive)
#link_directories(/home/marcelo/Desktop/RMAL/Continuum Robot/CR_Control/build/catkin_generated/stamps/DVS)

#Dynamixel
#link_directories(/home/dvs/DynamixelSDK/c++/build/linux64)
#include_directories("/home/dvs/DynamixelSDK/c++/build/linux64")
#include_directories("/home/dvs/DynamixelSDK/c++/include/dynamixel_sdk")
#find_library(DynamixelSDK_LIB DynamixelSDK)

#include directories
#include_directories(${PROJECT_SOURCE_DIR} include)

#include source code
file(GLOB H_FILES ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})
add_executable(DVS main.cpp ${H_FILES} ${CPP_FILES})
target_link_libraries(DVS ${VTK_LIBRARIES} Eigen3::Eigen catkin)
