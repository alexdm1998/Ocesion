cmake_minimum_required(VERSION 3.31.5)
project(Ocesion_Ad_Infinitum VERSION 0.1)
#Source files
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB_RECURSE SOURCE_FILES ./src/*.cpp ./src/*.c)


#Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/WindowManager)
#include_directories(${CMAKE_SOURCE_DIR}/src/EngineState)
#include_directories(${CMAKE_SOURCE_DIR}/src/GameLayer)
#include_directories(${CMAKE_SOURCE_DIR}/src/Viewport)
#include_directories(${CMAKE_SOURCE_DIR}/src/Camera)
link_directories(${CMAKE_SOURCE_DIR}/lib)


add_executable(Ocesion_Ad_Infinitum ${SOURCE_FILES})

target_link_libraries(Ocesion_Ad_Infinitum glfw3 gdi32)
