cmake_minimum_required(VERSION 3.14)
project(Concurrencia)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Concurrencia test_int.cpp)