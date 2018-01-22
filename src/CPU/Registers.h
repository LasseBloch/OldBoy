//
// Created by Lasse Lauritsen on 18/01/2018.
//

#ifndef OLDBOY_REGISTERS_H
#define OLDBOY_REGISTERS_H
#include <cstdint>
#include "Register.h"
#include "CombinedRegister.h"
#include "Flags.h"

using Reg8Bit = Register<uint8_t>;
using Reg16Bit = Register<uint16_t>;

class Registers {


public:
    Registers();
    // TODO: encapsulate again, problem the OpCodes class need to manipulate registers
    //    friend class CPU;
    //private:
    // The eight 8-bit general purpose registers
    Reg8Bit A;
    Reg8Bit B;
    Reg8Bit C;
    Reg8Bit D;
    Reg8Bit E;
    // Also used as Flag register
    Reg8Bit F;
    Reg8Bit H;
    Reg8Bit L;
    // Stack pointer
    Reg16Bit SP;
    // Program counter
    Reg16Bit PC;

    // Combined registers
    CombinedRegister AF;
    CombinedRegister BC;
    CombinedRegister DE;
    CombinedRegister HL;
    Flags Flag;

};

#endif //OLDBOY_REGISTERS_H
