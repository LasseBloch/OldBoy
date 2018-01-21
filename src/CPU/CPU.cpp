//
// Created by Lasse Lauritsen on 17/01/2018.
//
#include <iostream>

#include "CPU.h"

void CPU::regsTest() {

    std::bitset<8> test(regs.A());
    std::cout << "RegA: " << test << std::endl;

    regs.A = 0xFF;

    test = regs.A();
    std::cout << "RegA: " << test << std::endl;

    regs.A++;

    test = regs.A();
    std::cout << "RegA: " << test << std::endl;

    regs.A--;
    regs.A--;
    test = regs.A();
    std::cout << "RegA: " << test << std::endl;


    std::bitset<16> regAF(regs.AF());
    std::cout << "RegAF: " << regAF << std::endl;

    regs.A = 0xBE;
    regs.F = 0xEF;

    regAF = regs.AF();
    std::cout << "RegAF: " << regAF << std::endl;

    regs.AF = 0B0111001100110011;
    test = regs.A();
    std::cout << "RegA: " << test << std::endl;
    test = regs.F();
    std::cout << "RegF: " << test << std::endl;
    regAF = regs.AF();
    std::cout << "RegAF: " << regs.AF() << " "<< regAF << std::endl;
    regs.AF++;
    regAF = regs.AF();
    std::cout << "RegAF: " << regs.AF() << " " << regAF << std::endl;

    regs.AF = 1;
    std::cout << "RegAF: " <<  " " << regs.AF() << std::endl;
    regs.AF++;
    std::cout << "RegAF: " <<  " " << regs.AF() << std::endl;

    regs.Flag.Z() ? regs.Flag.setZ(false) : regs.Flag.setZ(true);

    regs.Flag.H() ? regs.Flag.setH(false) : regs.Flag.setH(true);
    regs.Flag.N() ? regs.Flag.setN(false) : regs.Flag.setN(true);
    regs.Flag.C() ? regs.Flag.setC(false) : regs.Flag.setC(true);

}