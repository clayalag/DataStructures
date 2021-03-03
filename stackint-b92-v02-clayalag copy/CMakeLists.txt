cmake_minimum_required(VERSION 3.15)
project(stackInt)

set(CMAKE_CXX_STANDARD 14)
include_directories(/Users/lee/Documents/ccom3034_0U1/catch_test_framework)
add_executable(stackInt main.cpp stackInt.cpp stackInt.h)
