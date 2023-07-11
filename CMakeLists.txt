cmake_minimum_required(VERSION 3.10)

# set the project name
project(EmployeeList)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the include directory
include_directories(include)

# add all the .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# add the executable
add_executable(EmployeeList ${SOURCES})
