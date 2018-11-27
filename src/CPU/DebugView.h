//
// Created by Lasse Bloch Lauritsen on 12/08/2018.
//

#ifndef OLDBOY_DEBUGVIEW_H
#define OLDBOY_DEBUGVIEW_H

#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>

class Registers;
class GBMemory;


// Display the value of registers to the render window
class DebugView {

public:
    DebugView(Registers& regs, GBMemory& memory);
    void clear();
    void render(sf::RenderWindow& window);
private:
    Registers& regs_;
    GBMemory& mem_;
    sf::Text regContent_;
    std::vector<sf::Text> memContent_;
    sf::Font font_;
    void printMemAroundPC();
    std::string format8BBitString(std::string regName, uint8_t val) const;
    std::string format16BBitString(std::string regName, uint16_t val) const;
    std::string printMemLocation(uint16_t location) const;
};

#endif //OLDBOY_DEBUGVIEW_H
