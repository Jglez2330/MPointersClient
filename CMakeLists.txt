cmake_minimum_required(VERSION 3.12)
project(MpointersClient)

set(CMAKE_CXX_STANDARD 17)

add_executable(MpointersClient main.cpp Socket.cpp Socket.h)