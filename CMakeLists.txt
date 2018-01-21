cmake_minimum_required(VERSION 3.9)
project(OldBoy)

set(CMAKE_CXX_STANDARD 14)

add_executable(OldBoy main.cpp src/CPU/CPU.cpp src/CPU/CPU.h src/CPU/Registers.cpp src/CPU/Registers.h src/CPU/Register.h src/CPU/CombinedRegister.cpp src/CPU/CombinedRegister.h src/CPU/Flags.cpp src/CPU/Flags.h)