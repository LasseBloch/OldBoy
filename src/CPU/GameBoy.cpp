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

    // Check that memory is zeored out in range 0x8000-9FFFF
    for (int n = 0x8000; n < 0x9FFF; n++)
    {
        std::printf("mem[%x]=%x\n", n, mem_[n]);
    }


    for (int n = 0; n<395000; n++) {
        CPU_.emulateCycle();
    }

    // Check that memory is zeored out in range 0x8000-9FFFF
    for (int n = 0x7FFA; n < 0x8002; n++)
    {
        std::printf("mem[%x]=%x\n", n, mem_[n]);
    }

    std::printf("mem[FF11]=%x\n", mem_[0xFF11]);
    std::printf("mem[FF12]=%x\n", mem_[0xFF12]);


}
