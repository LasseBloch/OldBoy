//
// Created by Lasse Bloch Lauritsen on 12/08/2018.
//

#include "DebugView.h"
#include "Registers.h"
#include "GBMemory.h"
#include <stdio.h>
#include <sstream>

DebugView::DebugView(Registers& regs, GBMemory& memory)
: regs_(regs), mem_(memory)
{
    font_.loadFromFile("arial.ttf");
    content_.setFont(font_);
    content_.setString("");
    content_.setCharacterSize(14);
    content_.setFillColor(sf::Color::White);
    //content_.setPosition();
}

void DebugView::render(sf::RenderWindow& window)
{
    std::string content;

    content.append(format8BBitString("A", regs_.A()));
    content.append(format8BBitString("B", regs_.B()));
    content.append(format8BBitString("C", regs_.C()));
    content.append(format8BBitString("D", regs_.D()));
    content.append(format8BBitString("E", regs_.E()));
    content.append(format8BBitString("F", regs_.F()));
    content.append(format8BBitString("L", regs_.L()));


    content.append(format16BBitString("PC", regs_.PC()));
    content.append(format16BBitString("SP", regs_.SP()));
    content.append(format16BBitString("AF", regs_.AF()));
    content.append(format16BBitString("BC", regs_.BC()));
    content.append(format16BBitString("DE", regs_.DE()));
    content.append(format16BBitString("HL", regs_.HL()));



    if (content != "")
    {
        content_.setString(content);
        window.draw(content_);
    }
}

std::string DebugView::format8BBitString(std::string regName, uint8_t val)
{
    std::stringstream temp;
    temp << regName << ": " << std::to_string(val) << "\t" << std::hex << (int)val << "\n";
    return std::string(temp.str());
}

std::string DebugView::format16BBitString(std::string regName, uint16_t val)
{
    std::stringstream temp;
    temp << regName << ": " << std::to_string(val) << " " << std::hex << val << "\n";
    return std::string(temp.str());
}

