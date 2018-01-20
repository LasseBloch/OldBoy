//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#ifndef OLDBOY_REGISTER_H
#define OLDBOY_REGISTER_H
#include <cstdint>


class Register {
public:
    Register& operator=(uint8_t val);
    uint8_t operator()();

private:
    uint8_t val_;
};

#endif //OLDBOY_REGISTER_H
