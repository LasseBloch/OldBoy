//
// Created by Lasse Lauritsen on 17/01/2018.
//
#include <iostream>

#include "CPU.h"

void CPU::regsTest() {

    std::bitset<8> test(regs_.A());
    std::cout << "RegA: " << test << std::endl;

    regs_.A = 0xFF;

    test = regs_.A();
    std::cout << "RegA: " << test << std::endl;

    regs_.A++;

    test = regs_.A();
    std::cout << "RegA: " << test << std::endl;

    regs_.A--;
    regs_.A--;
    test = regs_.A();
    std::cout << "RegA: " << test << std::endl;


    std::bitset<16> regAF(regs_.AF());
    std::cout << "RegAF: " << regAF << std::endl;

    regs_.A = 0xBE;
    regs_.F = 0xEF;

    regAF = regs_.AF();
    std::cout << "RegAF: " << regAF << std::endl;

    regs_.AF = 0B0111001100110011;
    test = regs_.A();
    std::cout << "RegA: " << test << std::endl;
    test = regs_.F();
    std::cout << "RegF: " << test << std::endl;
    regAF = regs_.AF();
    std::cout << "RegAF: " << regs_.AF() << " "<< regAF << std::endl;
    regs_.AF++;
    regAF = regs_.AF();
    std::cout << "RegAF: " << regs_.AF() << " " << regAF << std::endl;

    regs_.AF = 1;
    std::cout << "RegAF: " <<  " " << regs_.AF() << std::endl;
    regs_.AF++;
    std::cout << "RegAF: " <<  " " << regs_.AF() << std::endl;

    regs_.Flag.Z() ? regs_.Flag.setZ(false) : regs_.Flag.setZ(true);

    regs_.Flag.H() ? regs_.Flag.setH(false) : regs_.Flag.setH(true);
    regs_.Flag.N() ? regs_.Flag.setN(false) : regs_.Flag.setN(true);
    regs_.Flag.C() ? regs_.Flag.setC(false) : regs_.Flag.setC(true);

}
void CPU::initialize()
{
    // initialize registers and memory
    regs_.PC = 0x0000;
    lastOpcodeComplete = true;
}

void CPU::emulateCycle()
{

    // Fetch opcode
    auto opcodeVal = mem_[regs_.PC()];
    // The PC should not always be incremented
    regs_.PC++;
    // Decode opcode
    auto opCode = opCodes_.getOpcode(opcodeVal);
    // Execute opcode: Keep in mind some opcodes_ take multiple cycles to complete
    // TODO wait x clock cycles
    opCode.work();


}
CPU::CPU(GBMemory& mem) :mem_(mem), opCodes_(mem_, regs_)
{

}

void CPU::opCodesTest()
{
    opCodes_.executeOpcode(00);
    opCodes_.executeOpcode(0xBE);
    opCodes_.executeOpcode(0xFE);
    auto opCode = opCodes_.getOpcode(0x02);
    opCode.work();
}
