//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#include "CombinedRegister.h"

CombinedRegister::CombinedRegister(Register<uint8_t>& high, Register<uint8_t>& low) : high_(high), low_(low)
{

}

uint16_t CombinedRegister::operator()()
{
    val_ = (high_() << 8) | low_();
    return val_;
}

void CombinedRegister::operator++(int)
{
    val_++;
    low_ = val_;
    high_ = val_ >> 8;
}

void CombinedRegister::operator--(int)
{
    val_--;
    low_ = val_;
    high_ = val_ >> 8;
}


void CombinedRegister::operator=(uint16_t val)
{
    low_ = val;
    high_ = (val >> 8);
    val_ = val;
}
