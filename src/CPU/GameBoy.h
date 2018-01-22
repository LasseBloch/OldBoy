//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#ifndef OLDBOY_GAMEBOY_H
#define OLDBOY_GAMEBOY_H

#include "GBMemory.h"
#include "CPU.h"
class GameBoy {

public:
    GameBoy();
    void tick();

private:
    GBMemory mem_;
    CPU CPU_;
};

#endif //OLDBOY_GAMEBOY_H
