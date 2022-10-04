cmake_minimum_required(VERSION 3.16.3)
project(assignment)

set(CMAKE_CXX_STANDARD 11)

add_executable(SoftwareDesign ppm.cpp ppm.h pgm.cpp pgm.h
        ColorPixel.h grayPixel.h ColorPixel.cpp rotator.cpp Rotator.h)
