cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#Project name
project(ho5_imc)

#Where to find included source files
include_directories("${PROJECT_SOURCE_DIR}")

# Lists sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")


#Create a (static by default) library using all of IMC sources / headers
add_library(imc ${IMC_HEADERS} ${IMC_SOURCES})
add_library(socket Socket/DatagramSocket.h Socket/DatagramSocket.cpp)

add_executable(Hello hello.cpp)
add_executable(PlanSpecification planspec.cpp)
target_link_libraries(PlanSpecification imc socket)
