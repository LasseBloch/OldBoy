//
// Created by Lasse Lauritsen on 21/01/2018.
//

#ifndef OLDBOY_MEMORY_H
#define OLDBOY_MEMORY_H
/*
 * The following information are from "Game BoyTM CPU Manual"
 *  Interrupt Enable Register
 *  --------------------------- FFFF
 *  Internal RAM
 *  --------------------------- FF80
 *  Empty but unusable for I/O
 *  --------------------------- FF4C
 *  I/O ports
 *  --------------------------- FF00
 *  Empty but unusable for I/O
 *  --------------------------- FEA0
 *  Sprite Attrib Memory (OAM)
 *  --------------------------- FE00
 *  Echo of 8kB Internal RAM
 *  --------------------------- E000
 *  8kB Internal RAM
 *  --------------------------- C000
 *  8kB switchable RAM bank
 *  --------------------------- A000
 *  8kB Video RAM
 *  --------------------------- 8000 --
 *  16kB switchable ROM bank           |
 *  --------------------------- 4000   |  = 32kB Cartrigbe
 *  16kB ROM bank #0                   |
 *  --------------------------- 0000 --
 *
 *  The addresses E000-FE00 appear to access the internal RAM the same as C000-DE00.
 *  (i.e. If you write a byte to address E000 it will appear at C000 and E000. Similarly,
 *  writing a byte to C000 will appear at C000 and E000.)
 * /
class Memory {

};

#endif //OLDBOY_MEMORY_H
