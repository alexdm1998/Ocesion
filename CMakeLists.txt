cmake_minimum_required(VERSION 3.31.5)
project(Ocesion_Ad_Infinitum VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_definitions(-DGLEW_STATIC)

link_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)


target_link_libraries(${PROJECT_NAME}
    glew
    glfw3
    opengl32
    gdi32
)
