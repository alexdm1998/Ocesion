cmake_minimum_required(VERSION 3.31.5)
project(Ocesion_Ad_Infinitum VERSION 0.1)
#Source files
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)


add_executable(Ocesion_Ad_Infinitum ./src/main.cpp 
	./src/gl.c)

target_link_libraries(Ocesion_Ad_Infinitum glfw3 gdi32)
