cmake_minimum_required(VERSION 3.24)
project(Automate)

set(CMAKE_CXX_STANDARD 17)

add_executable(Automate main.cpp automStruct.h autom.cpp etats.cpp etatsStruct.h parsing.cpp)
