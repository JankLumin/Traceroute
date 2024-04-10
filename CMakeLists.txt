cmake_minimum_required(VERSION 3.27)
project(Traceroute)

set(CMAKE_CXX_STANDARD 17)

add_executable(Traceroute main.cpp
        tests.cpp
        funcions.h
        functions.cpp
)
