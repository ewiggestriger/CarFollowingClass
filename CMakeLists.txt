cmake_minimum_required(VERSION 3.13)
project(CarFollowingClass)

set(CMAKE_CXX_STANDARD 14)

add_executable(CarFollowingClass main.cpp Car.cpp Car.h Road.cpp Road.h EulersMethod.cpp EulersMethod.h)