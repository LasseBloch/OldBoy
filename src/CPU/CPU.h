//
// Created by Lasse Lauritsen on 17/01/2018.
//

#ifndef OLDBOY_CPU_H
#define OLDBOY_CPU_H
#include "Registers.h"
#include "GBMemory.h"

class CPU {
public:
    CPU(GBMemory& mem);
    // Initialize regs and memory
    void initialize();
    // Emulate one clock cycle
    void emulateCycle();
    // WHO need unit tests?
    void regsTest();
private:
    Registers regs;
    GBMemory& mem_;
};

#endif //OLDBOY_CPU_H
