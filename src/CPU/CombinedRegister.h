//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#ifndef OLDBOY_COMBINEDREGISTER_H
#define OLDBOY_COMBINEDREGISTER_H
#include "Register.h"

class CombinedRegister {
public:
    CombinedRegister(Register& high, Register& low);
private:
    Register& high_;
    Register& low_;
};

#endif //OLDBOY_COMBINEDREGISTER_H
