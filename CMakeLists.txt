cmake_minimum_required(VERSION 3.23)
project(assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(SoftwareDesign ppm.cpp ppm.h pgm.cpp pgm.h
        PixelFiles/ColorPixel.h PixelFiles/grayPixel.h PixelFiles/ColorPixel.cpp rotator.cpp Rotator.h)
