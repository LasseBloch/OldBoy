//
// Created by Lasse Lauritsen on 21/01/2018.
//

#include <fstream>
#include <assert.h>
#include <iostream>
#include "GBMemory.h"

void GBMemory::loadCartridge(std::string romPath)
{
    std::ifstream myFile;

    myFile.open(romPath, std::ios::in | std::ios::binary);

    uint8_t byte;
    uint16_t currentAddr = cartridgeStart_;
    while(myFile.good())
    {
        if (currentAddr <= cartridgeEnd_) {
            byte = myFile.get();
            mem_[currentAddr] = byte;
            currentAddr++;
        } 
        else
        {
            std::cout << "Ups GameBoy Cartridges are only supposed to hold 32kB" << std::endl;
            break;
        }
    }

    std::cout << "Done" << std::endl;

}
void GBMemory::loadBootLoader()
{
    for(int n = 0; n < bootSequence_.size(); n++)
    {
        mem_[n] = bootSequence_[n];
    }
}

uint8_t& GBMemory::operator[](int i)
{
    return mem_[i];
}

uint8_t& GBMemory::operator[](uint16_t i)
{
    return mem_[i];
}
