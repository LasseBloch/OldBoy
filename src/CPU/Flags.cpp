//
// Created by Lasse Lauritsen on 21/01/2018.
//

#include <iostream>
#include <cassert>
#include "Flags.h"
Flags::Flags(Register<uint8_t>& reg) : flagRegister_(reg)
{

}

bool Flags::Z() const
{
    return (flagRegister_() & Z_);
}

void Flags::setZ(bool val)
{
    auto flagRegBefore = flagRegister_;
    flagRegister_ = val ? flagRegister_() | Z_ : flagRegister_() & (flagRegister_() ^ Z_);
    if (Z())
    {
        if (!val)
        {
            assert(false);
        }
        //std::cout << "Zero flag set" << std::endl;
    }
    else
    {
        if (val)
        {
            assert(false);
        }
        //std::cout << "Zero flag reset" << std::endl;
    }
}

bool Flags::N() const
{
    return (flagRegister_() & N_);
}

void Flags::setN(bool val)
{
    flagRegister_ = val ? flagRegister_() | C_ : flagRegister_() &  (flagRegister_() ^ C_);
}

bool Flags::H() const
{
    return (flagRegister_() | H_);
}

void Flags::setH(bool val)
{
    flagRegister_ = val ? flagRegister_() | H_ : flagRegister_() & (flagRegister_() ^ H_);
}

bool Flags::C() const
{
    return (flagRegister_() | C_);
}

void Flags::setC(bool val)
{
    flagRegister_ = val ? flagRegister_() | C_ : flagRegister_() & (flagRegister_() ^ C_);
}

void Flags::resetAllFlags()
{
    flagRegister_ = 0;
}
