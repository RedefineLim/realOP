cmake_minimum_required(VERSION 3.24)
project(Project06)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project06
        Calculator.h
        setCalcu.cpp
        useCalcu.cpp Person.hpp)
