//
// Created by Lasse Lauritsen on 18/01/2018.
//

#include "Registers.h"
uint8_t Registers::getA() const
{
    return A_;
}

void Registers::setA(uint8_t A)
{
    Registers::A_ = A;
}

uint8_t Registers::getB() const
{
    return B_;
}

void Registers::setB(uint8_t B)
{
    Registers::B_ = B;
}

uint8_t Registers::getC() const
{
    return C_;
}

void Registers::setC(uint8_t C)
{
    Registers::C_ = C;
}

uint8_t Registers::getD() const
{
    return D_;
}

void Registers::setD(uint8_t D)
{
    Registers::D_ = D;
}

uint8_t Registers::getE() const
{
    return E_;
}

void Registers::setE(uint8_t E)
{
    Registers::E_ = E;
}

uint8_t Registers::getH() const
{
    return H_;
}

void Registers::setH(uint8_t H)
{
    Registers::H_ = H;
}

uint8_t Registers::getL() const
{
    return L_;
}

void Registers::setL(uint8_t L)
{
    Registers::L_ = L;
}

uint16_t Registers::getSP() const
{
    return SP_;
}

void Registers::setSP(uint16_t SP)
{
    Registers::SP_ = SP;
}

uint16_t Registers::getPC() const
{
    return PC_;
}

void Registers::setPC(uint16_t PC)
{
    Registers::PC_ = PC;
}

uint16_t Registers::getAF() const
{
    return (A_ << 8) | F_;
}

uint8_t Registers::getF() const
{
    return F_;
}

void Registers::setF(uint8_t F)
{
    F_ = F;
}

void Registers::setAF(uint16_t AF)
{
    A_ = AF;
    F_ = AF >> 8;
}
