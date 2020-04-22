cmake_minimum_required(VERSION 3.10.2)
project(OOP_Tema_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(OOP_Tema_2 main.cpp headers/object.h headers/objectArray.h headers/point.h headers/complexNum.h sources/point.cpp sources/complexNum.cpp sources/objectArray.cpp sources/exceptions/index_out_of_range.cpp headers/exceptions/index_out_of_range.h sources/object.cpp)