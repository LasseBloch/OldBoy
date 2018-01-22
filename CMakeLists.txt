cmake_minimum_required(VERSION 3.9)
project(OldBoy)

set(CMAKE_CXX_STANDARD 17)

add_executable(OldBoy main.cpp src/CPU/CPU.cpp src/CPU/CPU.h src/CPU/Registers.cpp src/CPU/Registers.h src/CPU/Register.h src/CPU/CombinedRegister.cpp src/CPU/CombinedRegister.h src/CPU/Flags.cpp src/CPU/Flags.h src/CPU/GBMemory.cpp src/CPU/GBMemory.h src/CPU/GameBoy.cpp src/CPU/GameBoy.h)