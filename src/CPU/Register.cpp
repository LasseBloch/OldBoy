//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#include "Register.h"
uint8_t Register::operator()()
{
    return val_;
}

Register& Register::operator=(const uint8_t rhs)
{
    val_ = rhs;
}
