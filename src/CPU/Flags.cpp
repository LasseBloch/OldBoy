//
// Created by Lasse Lauritsen on 21/01/2018.
//

#include "Flags.h"
Flags::Flags(Register<uint8_t>& reg) : flagRegister_(reg)
{

}

bool Flags::Z() const
{
    return (flagRegister_() | Z_);
}

void Flags::setZ(bool val)
{
    flagRegister_ = val ? flagRegister_() | Z_ : flagRegister_() ^ Z_;
}

bool Flags::N() const
{
    return (flagRegister_() | N_);
}

void Flags::setN(bool val)
{
    flagRegister_ = val ? flagRegister_() | C_ : flagRegister_() ^ C_;
}

bool Flags::H() const
{
    return (flagRegister_() | H_);
}

void Flags::setH(bool val)
{
    flagRegister_ = val ? flagRegister_() | H_ : flagRegister_() ^ H_;
}

bool Flags::C() const
{
    return (flagRegister_() | C_);
}

void Flags::setC(bool val)
{
    flagRegister_ = val ? flagRegister_() | C_ : flagRegister_() ^ C_;
}

void Flags::resetAllFlags()
{
    flagRegister_ = 0;
}
