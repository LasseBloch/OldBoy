//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "OpCodes.h"

OpCodes::OpCodes(GBMemory& mem_, Registers& regs_)
        :mem_(mem_), regs_(regs_)
{
    // Initialize all opcodes_ to not implemented
    for (int n = 0; n<256; n++) {
        OpCode temp;
        temp.opCode = n;
        temp.work = [=] { std::printf("OpCode %X is not implemented\n", n); };
        opcodes_[n] = temp;
    }

    // 16-Bit Loads

    // LD SP params nn
    {
        auto& LDSP = opcodes_[0x31];
        LDSP.opCode = 0x31;
        LDSP.cyclesToComplete = 12;
        LDSP.name = "LDSP";
        LDSP.work = [&] {
          regs_.SP = (mem_[regs_.PC()] << 8 | mem_[regs_.PC()+1]);
          // increment PC because this operation takes two bytes from mem
          regs_.PC++;
          regs_.PC++;
        };
    }

    // 8 Bit ALU

    // XOR n
    // Logical exclusive OR n with register A, result in A

    // XOR A
    {
        auto& LDSP = opcodes_[0xAF];
        LDSP.opCode = 0xAF;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR A";
        LDSP.work = [&] {
          xor_a(regs_.A());
        };
    }

    // XOR B
    {
        auto& LDSP = opcodes_[0xA8];
        LDSP.opCode = 0xA8;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR B";
        LDSP.work = [&] {
          xor_a(regs_.B());
        };
    }

    // XOR C
    {
        auto& LDSP = opcodes_[0xA9];
        LDSP.opCode = 0xA9;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR C";
        LDSP.work = [&] {
          xor_a(regs_.C());
        };
    }

    // XOR D
    {
        auto& LDSP = opcodes_[0xAA];
        LDSP.opCode = 0xAA;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR D";
        LDSP.work = [&] {
          xor_a(regs_.D());
        };
    }

    // XOR E
    {
        auto& LDSP = opcodes_[0xAB];
        LDSP.opCode = 0xAB;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR E";
        LDSP.work = [&] {
          xor_a(regs_.E());
        };
    }

    // XOR H
    {
        auto& LDSP = opcodes_[0xAC];
        LDSP.opCode = 0xAC;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR H";
        LDSP.work = [&] {
          xor_a(regs_.H());
        };
    }

    // XOR L
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAD;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR L";
        LDSP.work = [&] {
          xor_a(regs_.L());
        };
    }

    // XOR HL
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAE;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "XOR HL";
        LDSP.work = [&] {
          xor_a(mem_[regs_.HL()]);
        };
    }

    // XOR #
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAE;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "XOR HL";
        LDSP.work = [&] {
          xor_a(mem_[regs_.PC()]);
        };
    }
}

void OpCodes::executeOpcode(uint8_t opcode)
{
    opcodes_[opcode].work();
}

OpCode& OpCodes::getOpcode(uint8_t opcode)
{
    return opcodes_[opcode];
}

void OpCodes::resetFlags()
{
    regs_.Flag.resetAllFlags();
}

void OpCodes::setZ()
{
    regs_.Flag.setZ(true);
}

void OpCodes::xor_a(uint8_t val)
{
    resetFlags();
    regs_.A = (regs_.A() ^ val);
    if (regs_.A()==0) {
        setZ();
    }
}
