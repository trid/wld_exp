cmake_minimum_required(VERSION 3.5)
project(wld_exp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_definitions(-DSFML_STATIC)

add_subdirectory(meng)
add_subdirectory(world)
