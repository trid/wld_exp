cmake_minimum_required(VERSION 3.5)
project(meng)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Application.cpp
        State.cpp
        view/Screen.cpp ScriptManager.cpp ScriptManager.h)

set(VIEW_SRC
        view/View.cpp view/TextureManager.cpp view/TextureManager.h)

find_package(Lua REQUIRED)

include_directories(${LUA_INCLUDEDIR})

add_library(meng STATIC
        ${SOURCE_FILES} ${VIEW_SRC})