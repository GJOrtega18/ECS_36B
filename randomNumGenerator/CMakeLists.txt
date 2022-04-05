cmake_minimum_required(VERSION 3.13)
project(randomNumGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(randomNumGenerator main.cpp RandomIntVector.cpp RandomIntVector.h)