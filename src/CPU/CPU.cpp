//
// Created by Lasse Lauritsen on 17/01/2018.
//
#include <iostream>
#include <cassert>

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

    regs_.Flag.resetAllFlags();
    regs_.Flag.Z() ? regs_.Flag.setZ(false) : regs_.Flag.setZ(true);
    assert(regs_.Flag.Z() == true);
    regs_.Flag.setZ(true);
    assert(regs_.Flag.Z() == true);
    regs_.Flag.setZ(false);
    assert(regs_.Flag.Z() == false);


    regs_.Flag.H() ? regs_.Flag.setH(false) : regs_.Flag.setH(true);
    regs_.Flag.N() ? regs_.Flag.setN(false) : regs_.Flag.setN(true);
    regs_.Flag.C() ? regs_.Flag.setC(false) : regs_.Flag.setC(true);


    regs_.HL = 0xFFFF;
    assert(regs_.HL() == 0xFFFF);
    regs_.HL--;
    assert(regs_.HL() == 0xFFFE);
    regs_.HL++;
    assert(regs_.HL() == 0xFFFF);

    regs_.HL = 0x00FF;
    std::printf("H is %x\n", regs_.H());
    assert(regs_.H() == 0x00);
    assert(regs_.L() == 0xFF);
    regs_.HL++;
    assert(regs_.HL() == 0x0100);
    assert(regs_.H() == 0x01);
    assert(regs_.L() == 0x00);

}
void CPU::initialize()
{
    // initialize registers and memory
    regs_.PC = 0x0000;
    regs_.SP = 0xFFFE;
    regs_.A = 0xFE;
}

void CPU::emulateCycle()
{

    if (cycleCount_ >= cycleCountWhenComplete_) {
        cycleCountWhenComplete_ = cycleCount_;
        // Fetch opcode
        // Assume opcode fetch takes 4 cycles
        auto opcodeVal = mem_[regs_.PC()];
        cycleCountWhenComplete_ += 4;
        std::printf("%4X ", regs_.PC());
        regs_.PC++;
        // Decode opcode
        auto opCode = opCodes_.getOpcode(opcodeVal);
        // Execute opcode: Keep in mind some opcodes_ take multiple cycles to complete
        cycleCountWhenComplete_ += opCode.cyclesToComplete;
        std::printf("Exe opcode: %x - %s\n", opCode.opCode, opCode.name.c_str());
        opCode.work();
    }
    cycleCount_++;

}
CPU::CPU(GBMemory& mem) :mem_(mem), opCodes_(mem_, regs_)
{

}

void CPU::opCodesTest()
{
    return;
    opCodes_.executeOpcode(00);
    opCodes_.executeOpcode(0xBE);
    opCodes_.executeOpcode(0xFE);
    auto opCode = opCodes_.getOpcode(0x02);
    opCode.work();
}

Registers& CPU::getRegs()
{
    return regs_;
}
void CPU::runToNextPc()
{
    auto currentPC = regs_.PC();

    while (currentPC == regs_.PC() ) {
        emulateCycle();
    }
}
