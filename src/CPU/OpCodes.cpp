//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "OpCodes.h"

OpCodes::OpCodes(GBMemory& mem_, Registers& regs_):mem_(mem_), regs_(regs_)
{
    // Initialize all opcodes_ to not implemented
    for (uint8_t n = 0; n < 255; n++)
    {
        OpCode temp;
        temp.opCode = n;
        temp.work = [=]{std::printf("OpCode %X is not implemented\n", n);};
        opcodes_[n] = temp;
    }

    // 16-Bit Loads

    // LD SP params nn
    {
        auto& LDSP = opcodes_[0x31];
        LDSP.opCode = 0x31;
        LDSP.cyclesToComplete = 12;
        LDSP.name = "LDSP";
        LDSP.work = [&]{
          regs_.SP = (mem_[regs_.PC()] << 8 | mem_[regs_.PC() + 1]);
          // increment PC because this operation takes two bytes from mem
          regs_.PC++;
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
