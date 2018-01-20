//
// Created by Lasse Lauritsen on 18/01/2018.
//

#ifndef OLDBOY_REGISTERS_H
#define OLDBOY_REGISTERS_H
#include <cstdint>


class Registers {


public:
    uint8_t getA() const;
    void setA(uint8_t A);
    uint8_t getB() const;
    void setB(uint8_t B);
    uint8_t getC() const;
    void setC(uint8_t C);
    uint8_t getD() const;
    void setD(uint8_t D);
    uint8_t getE() const;
    void setE(uint8_t E);
    uint8_t getF() const;
    void setF(uint8_t F);
    uint8_t getH() const;
    void setH(uint8_t H);
    uint8_t getL() const;
    void setL(uint8_t L);
    uint16_t getSP() const;
    void setSP(uint16_t SP);
    uint16_t getPC() const;
    void setPC(uint16_t PC);

    // Some instructions allows you to access the registers as 16bits by paring them
    // This can be done in the following manner (AF, BC, DE and HL)
    uint16_t getAF() const;
    void setAF(uint16_t AF);
    uint16_t getBC() const;
    void setBC(uint16_t BC);
    uint16_t getDE() const;
    void setDE(uint16_t DE);
    uint16_t getDL() const;
    void setDL(uint16_t DL);


private:
    // The eight 8-bit general purpose registers
    uint8_t A_;
    uint8_t B_;
    uint8_t C_;
    uint8_t D_;
    uint8_t E_;
    uint8_t F_;
    uint8_t H_;
    uint8_t L_;
    // Stack pointer
    uint16_t SP_;
    // Program counter
    uint16_t PC_;



};

#endif //OLDBOY_REGISTERS_H
