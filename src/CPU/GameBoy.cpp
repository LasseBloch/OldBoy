//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "GameBoy.h"

GameBoy::GameBoy() : CPU_(mem_)
{
    mem_.loadBootLoader();
    // just for testing
    CPU_.regsTest();
    CPU_.opCodesTest();
    CPU_.initialize();
    CPU_.emulateCycle();
}
