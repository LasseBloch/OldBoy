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
    std::cout << "RegAF: " << regAF << std::endl;

}