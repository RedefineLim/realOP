cmake_minimum_required(VERSION 3.24)
project(Project03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project03
        bankto.cpp
        bankto.h
        usebanktool.cpp)
