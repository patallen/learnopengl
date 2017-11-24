project(opengltut)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_FLAGS "-lglfw")

add_executable(opengltut main.cpp glad.c)

find_package(OpenGL REQUIRED)

include_directories(/usr/local/include)

