//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#ifndef OLDBOY_GAMEBOY_H
#define OLDBOY_GAMEBOY_H

#include "GBMemory.h"
#include "CPU.h"
#include <SFML/Graphics/RenderWindow.hpp>
class GameBoy {

public:
    GameBoy();
    void tick();

    void beginDraw();   // Clear the window
    void endDraw();     // Display the changes

private:
    GBMemory mem_;
    CPU CPU_;
    sf::RenderWindow* window_;
};

#endif //OLDBOY_GAMEBOY_H
