//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#ifndef OLDBOY_OPCODES_H
#define OLDBOY_OPCODES_H

#include <functional>
#include <string>
#include "Registers.h"
#include "GBMemory.h"
#include <iostream>


// This might be the most stupid idea ever
struct OpCode
{
    uint8_t opCode = 0;
    uint8_t cyclesToComplete = 0;
    std::string name = "Not impplemented";
    std::function<void()> work;//(Registers& regs, GBMemory &memory)> work;
};


class OpCodes {
    friend class CPU;
public:
    OpCodes(GBMemory& mem_, Registers& regs_);
    void executeOpcode(uint8_t opcode);
    OpCode& getOpcode(uint8_t opcode);
private:
    std::array<OpCode, 256> opcodes_;
    // references to be given to the lambdas
    Registers &regs_;
    GBMemory &mem_;

    void xor_a(uint8_t val);
    void resetFlags();
    void setZ();

};

#endif //OLDBOY_OPCODES_H
