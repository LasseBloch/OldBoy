//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#ifndef OLDBOY_COMBINEDREGISTER_H
#define OLDBOY_COMBINEDREGISTER_H
#include "Register.h"

class CombinedRegister {
public:
    CombinedRegister(Register<uint8_t>& high, Register<uint8_t>& low);
    uint16_t operator()() const;
    void operator=(uint16_t val);
private:
    Register<uint8_t>& high_;
    Register<uint8_t>& low_;
};

#endif //OLDBOY_COMBINEDREGISTER_H
