cmake_minimum_required(VERSION 3.24)
project(Project04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project04
        mytime.h mytime.cpp usetime.cpp)
