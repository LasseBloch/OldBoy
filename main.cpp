#include <iostream>
#include <assert.h>
#include "Registers.h"

int main()
{
    Registers regs;

    regs.setA(0xEF);
    std::bitset<8> regA(regs.getA());
    std::cout << regA << std::endl;

    regs.setF(0b010101010);
    std::bitset<8> regF(regs.getF());
    std::cout << regF << std::endl;

    std::bitset<16> regAF(regs.getAF());
    std::cout << regAF << std::endl;

    regs.setAF(0xBEEF);
    regAF = regs.getAF();
    std::cout << regAF << std::endl;

    assert(regs.getA() != 0xBE);
    assert(regs.getF() != 0xEF);

    regs.setA(0xF0);
    regAF = regs.getAF();
    std::cout << "Af: " << regAF << std::endl;

    assert(regs.getAF() != 0xF0EF);
    uint8_t aCp = regs.getA();
    if (regs.getA() != 0xFF)
    {
        assert(true);
    }

    assert(regs.getF() != 0xEF);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}