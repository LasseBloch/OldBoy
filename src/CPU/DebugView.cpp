//
// Created by Lasse Bloch Lauritsen on 12/08/2018.
//

#include "DebugView.h"
#include "Registers.h"
#include "GBMemory.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <iomanip>

DebugView::DebugView(Registers& regs, GBMemory& memory)
: regs_(regs), mem_(memory)
{
    font_.loadFromFile("arial.ttf");
    regContent_.setFont(font_);
    regContent_.setString("");
    regContent_.setCharacterSize(14);
    regContent_.setFillColor(sf::Color::White);
    //content_.setPosition();
}

void DebugView::render(sf::RenderWindow& window)
{
    std::string registerDebugStr;

    registerDebugStr.append(format8BBitString("A", regs_.A()));
    registerDebugStr.append(format8BBitString("B", regs_.B()));
    registerDebugStr.append(format8BBitString("C", regs_.C()));
    registerDebugStr.append(format8BBitString("D", regs_.D()));
    registerDebugStr.append(format8BBitString("E", regs_.E()));
    registerDebugStr.append(format8BBitString("F", regs_.F()));
    registerDebugStr.append(format8BBitString("L", regs_.L()));


    registerDebugStr.append(format16BBitString("PC", regs_.PC()));
    registerDebugStr.append(format16BBitString("SP", regs_.SP()));
    registerDebugStr.append(format16BBitString("AF", regs_.AF()));
    registerDebugStr.append(format16BBitString("BC", regs_.BC()));
    registerDebugStr.append(format16BBitString("DE", regs_.DE()));
    registerDebugStr.append(format16BBitString("HL", regs_.HL()));

    printMemAroundPC();


    if (registerDebugStr != "")
    {
        regContent_.setString(registerDebugStr);
        window.draw(regContent_);
    }

    if (!memContent_.empty())
    {
        for (auto& memDump : memContent_)
        {
            window.draw(memDump);
        }
    }

}

std::string DebugView::format8BBitString(std::string regName, uint8_t val) const
{
    std::stringstream temp;
    temp << regName << ": " << std::to_string(val) << "\t" << std::hex << (int)val << '\n';
    return std::string(temp.str());
}

std::string DebugView::format16BBitString(std::string regName, uint16_t val) const
{
    std::stringstream temp;
    temp << regName << ": " << std::to_string(val) << " " << std::hex << val << '\n';
    return std::string(temp.str());
}



void DebugView::printMemAroundPC()
{
    memContent_.clear();
    int idx = 0;

    for(int n = regs_.PC() - 5; n <= regs_.PC() + 5; n++)
    {
        if (n >= 0)
        {
            idx++;
            auto memDump = sf::Text(printMemLocation(n), font_, 16);
            memDump.setPosition(700, 10 + memDump.getCharacterSize() * idx);
            if (n == regs_.PC())
            {
                memDump.setFillColor(sf::Color::Red);
            }
            memContent_.push_back(memDump);
        }
    }

    //auto memDump = sf::Text(printMemLocation(regs_.PC()), font_, 16);
    //memDump.setPosition(200,200);
}

std::string DebugView::printMemLocation(uint16_t location) const
{
    std::stringstream temp;
    temp << std::hex << std::setw(2) << std::setfill('0') << location << ": " << std::hex << std::setw(2) << std::setfill('0') << (int)mem_[location] << '\n';
    return std::string(temp.str());

}

