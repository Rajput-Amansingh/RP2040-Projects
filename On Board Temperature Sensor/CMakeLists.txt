# CMake will look for this file to build the system

# Mentioned the required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include the Cmake file
include(pico_sdk_import.cmake)

# Mention the standard of C and C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initiate the Pico_sdk
pico_sdk_init()

# Mention the Projec for the CMake to Build
project(temperature)

# Include the  project files tobe build
add_executable(temperature temperature.c)

# Include the header libraries used  in main.c file
target_link_libraries(temperature 
pico_stdlib
hardware_adc
)

# Enable the USB Serial and Disable the UART
pico_enable_stdio_usb(temperature 1)
pico_enable_stdio_uart(temperature 0)

# Include the project so cmake will generate the necessary upload files    
pico_add_extra_outputs(temperature)
