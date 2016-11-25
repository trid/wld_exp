cmake_minimum_required(VERSION 3.5)
project(meng)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Application.cpp
        State.cpp State.h)

add_library(meng STATIC
        ${SOURCE_FILES})