//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#include "CombinedRegister.h"

CombinedRegister::CombinedRegister(Register<uint8_t>& high, Register<uint8_t>& low) : high_(high), low_(low)
{

}

uint16_t CombinedRegister::operator()() const
{
    return (high_() << 8) | low_();
}

void CombinedRegister::operator=(uint16_t val)
{
    high_ = val;
    low_ = val >> 8;
}
