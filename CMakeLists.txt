cmake_minimum_required(VERSION 3.9)
project(OldBoy)

set(CMAKE_CXX_STANDARD 14)

add_executable(OldBoy main.cpp CPU.cpp CPU.h Registers.cpp Registers.h)