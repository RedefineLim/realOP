cmake_minimum_required(VERSION 3.24)
project(Project05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project05
        "polymorphic 01.h"
        "polymorphic 02.cpp"
        "polymorphic 03.cpp")
