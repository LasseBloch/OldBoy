//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "GameBoy.h"
#include "DebugView.h"
#include <SFML/Window.hpp>
#include <exception>
#include <chrono>
#include <zconf.h>

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

    if (false)
    {
        window_ = new sf::RenderWindow({800,600, 32}, "Old boy");
        DebugView dbView(CPU_.getRegs(), mem_);

        // Run emu as long as window is open
        while (window_->isOpen()) {

            for (int n = 0; n<1000; n++) {
                CPU_.emulateCycle();
            }

            // Check all the windows events that where triggered since last iteration of the loop
            sf::Event event;
            while (window_->pollEvent(event)) {

                // Close requested
                if (event.type==sf::Event::Closed) {
                    window_->close();
                }
            }
            window_->clear(sf::Color::Black);
            dbView.render(*window_);
            window_->display();
        }
    }

    try {
        while(true)
        {
            auto startTime = std::chrono::system_clock::now();
            for (int n = 0; n < 1000; n++)
            {
                CPU_.emulateCycle();
            }
            auto endTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedTime =  endTime - startTime;
            std::cout << "Elasped time for 1000 cycles: " << elapsedTime.count() << '\n';
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }



    // Check that memory is zeored out in range 0x8000-9FFFF
    for (int n = 0x7FFA; n < 0x8002; n++)
    {
        std::printf("mem[%x]=%x\n", n, mem_[n]);
    }

    std::printf("mem[FF11]=%x\n", mem_[0xFF11]);
    std::printf("mem[FF12]=%x\n", mem_[0xFF12]);


}
