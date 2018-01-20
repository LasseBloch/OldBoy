//
// Created by Lasse Lauritsen on 17/01/2018.
//

#ifndef OLDBOY_CPU_H
#define OLDBOY_CPU_H
#include "Registers.h"

class CPU {
public:
    // HOW need unit tests?
    void regsTest();
private:
    Registers regs;
};

#endif //OLDBOY_CPU_H
