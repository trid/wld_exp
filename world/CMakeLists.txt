project(World)

set(SOURCE_FILES
        Agent.cpp
        main.cpp
        Location.cpp
        World.cpp
        WorldState.cpp)

set(BEHAVIOR_SOURCE_FILES
        Behaviour/State.cpp
        Behaviour/StateQueue.cpp)

set(VIEW_SRC view/WorldView.cpp view/WorldView.h view/AgentView.cpp view/AgentView.h)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem)
include_directories(${BOOST_INCLUDEDIR})

include_directories(${meng_SOURCE_DIR})

add_executable(world ${SOURCE_FILES} ${BEHAVIOR_SOURCE_FILES} ${VIEW_SRC})
target_link_libraries(world meng)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_LIBRARIES True)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})


find_package(SFML 2 REQUIRED graphics network audio window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(world ${SFML_LIBRARIES})
    target_link_libraries(world ${Boost_LIBRARIES})
endif()

target_link_libraries(world ${OPENGL_LIBRARIES})
if (WIN32)
    target_link_libraries(world jpeg)
    target_link_libraries(world winmm)
endif(WIN32)