//
// Created by Lasse Lauritsen on 21/01/2018.
//

#ifndef OLDBOY_FLAGS_H
#define OLDBOY_FLAGS_H
#include "Register.h"


class Flags {
public:
    Flags(Register<uint8_t>& reg);
    bool Z() const;
    void setZ(bool val);
    bool N() const;
    void setN(bool val);
    bool H() const;
    void setH(bool val) const;
    bool C() const;
    void setC(bool val);

private:
    Register<uint8_t>& flagRegister_;
    /*
     * Zero Flag (Z):
     * This bit is set when the result of a math operation is zero or two values match when using the CP instruction.
     */
    static constexpr uint8_t Z_ = 0x80;
     /*
      * Subtract Flag (N):
      * This bit is set if a subtraction was performed in the last math instruction.
      */
    static constexpr uint8_t N_ = 0x40;
    /*
     * Half Carry Flag (H):
     * This bit is set if a carry occurred from the lower nibble in the last math operation.
     */
    static constexpr uint8_t H_ = 0x20;
    /*
     * Carry Flag (C):
     * This bit is set if a carry occurred from the last math operation or if register A is the smaller value when executing the CP instruction.
     */
    static constexpr uint8_t C_ = 0x10;
};

#endif //OLDBOY_FLAGS_H
