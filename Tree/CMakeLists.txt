cmake_minimum_required(VERSION 3.2)
project(Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Tree ${SOURCE_FILES} Solution5_1.cpp Solution5_1.h)