//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "OpCodes.h"

OpCodes::OpCodes()
{
    for (uint8_t n = 0; n < 255; n++)
    {
        OpCode temp;
        temp.opCode = n;
        temp.work = [=]{std::printf("OpCode %X is not implemented\n", n);};
        opcodes[n] = temp;
    }
}
void OpCodes::executeOpcode(uint8_t opcode)
{
    opcodes[opcode].work();
}
