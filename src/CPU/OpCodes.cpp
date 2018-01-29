//
// Created by Lasse Bloch Lauritsen on 22/01/2018.
//

#include "OpCodes.h"

OpCodes::OpCodes(GBMemory& mem_, Registers& regs_)
        :mem_(mem_), regs_(regs_)
{
    // Initialize all opcodes_ to not implemented
    for (int n = 0; n<256; n++) {
        OpCode temp;
        temp.opCode = n;
        temp.work = [=] { std::printf("OpCode %X is not implemented\n", n); };
        opcodes_[n] = temp;
    }

    // 16-Bit Loads

    // LD SP params nn
    {
        auto& LDSP = opcodes_[0x31];
        LDSP.opCode = 0x31;
        LDSP.cyclesToComplete = 12;
        LDSP.name = "LDSP";
        LDSP.work = [&] {
          regs_.SP = (mem_[regs_.PC()] << 8 | mem_[regs_.PC()+1]);
          // increment PC because this operation takes two bytes from mem
          regs_.PC++;
          regs_.PC++;
        };
    }

    // 8 Bit ALU

    // 8-Bit loads

    // LD nn.n
    // Use with nn = B, C, D, E, H, L, BC, DE, HL, SP
    // n = 8 bit immediate values
    {
        auto& LDSP = opcodes_[0x06];
        LDSP.opCode = 0x06;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD B,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.B = mem_[regs_.PC()];
        };
    }

    {
        auto& LDSP = opcodes_[0x0E];
        LDSP.opCode = 0x0E;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD C,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.C = mem_[regs_.PC()];
        };
    }

    {
        auto& LDSP = opcodes_[0x16];
        LDSP.opCode = 0x16;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD D,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.D = mem_[regs_.PC()];
        };
    }

    {
        auto& LDSP = opcodes_[0x1E];
        LDSP.opCode = 0x1E;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD E,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.E = mem_[regs_.PC()];
        };
    }

    {
        auto& LDSP = opcodes_[0x26];
        LDSP.opCode = 0x26;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD H,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.H = mem_[regs_.PC()];
        };
    }

    {
        auto& LDSP = opcodes_[0x2E];
        LDSP.opCode = 0x2E;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD L,n";
        LDSP.work = [&] {
          regs_.PC++;
          regs_.L = mem_[regs_.PC()];
        };
    }

    // LD r1, r2
    // put value r2 into r1
    // Use with: r1, r2 = A, B, C, D, E, H, L, (HL)
    {
        auto& LDSP = opcodes_[0x7F];
        LDSP.opCode = 0x7F;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,A";
        LDSP.work = [&] {
          regs_.A = regs_.A();
        };
    }

    {
        auto& LDSP = opcodes_[0x78];
        LDSP.opCode = 0x78;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,B";
        LDSP.work = [&] {
          regs_.A = regs_.B();
        };
    }

    {
        auto& LDSP = opcodes_[0x79];
        LDSP.opCode = 0x79;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,C";
        LDSP.work = [&] {
          regs_.A = regs_.C();
        };
    }

    {
        auto& LDSP = opcodes_[0x7A];
        LDSP.opCode = 0x7A;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,D";
        LDSP.work = [&] {
          regs_.A = regs_.D();
        };
    }

    {
        auto& LDSP = opcodes_[0x7B];
        LDSP.opCode = 0x7B;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,E";
        LDSP.work = [&] {
          regs_.A = regs_.E();
        };
    }

    {
        auto& LDSP = opcodes_[0x7C];
        LDSP.opCode = 0x7C;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,H";
        LDSP.work = [&] {
          regs_.A = regs_.H();
        };
    }

    {
        auto& LDSP = opcodes_[0x7D];
        LDSP.opCode = 0x7D;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD A,L";
        LDSP.work = [&] {
          regs_.A = regs_.L();
        };
    }

    {
        auto& LDSP = opcodes_[0x7E];
        LDSP.opCode = 0x7E;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD A,A";
        LDSP.work = [&] {
          regs_.A = mem_[regs_.HL()];
        };
    }

    {
        auto& LDSP = opcodes_[0x40];
        LDSP.opCode = 0x40;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,B";
        LDSP.work = [&] {
          regs_.B = regs_.B();
        };
    }

    {
        auto& LDSP = opcodes_[0x41];
        LDSP.opCode = 0x41;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,C";
        LDSP.work = [&] {
          regs_.B = regs_.C();
        };
    }

    {
        auto& LDSP = opcodes_[0x42];
        LDSP.opCode = 0x42;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,D";
        LDSP.work = [&] {
          regs_.B = regs_.D();
        };
    }

    {
        auto& LDSP = opcodes_[0x43];
        LDSP.opCode = 0x43;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,E";
        LDSP.work = [&] {
          regs_.B = regs_.E();
        };
    }

    {
        auto& LDSP = opcodes_[0x44];
        LDSP.opCode = 0x44;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,H";
        LDSP.work = [&] {
          regs_.B = regs_.H();
        };
    }

    {
        auto& LDSP = opcodes_[0x45];
        LDSP.opCode = 0x45;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD B,L";
        LDSP.work = [&] {
          regs_.B = regs_.H();
        };
    }

    {
        auto& LDSP = opcodes_[0x46];
        LDSP.opCode = 0x46;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD B,HL";
        LDSP.work = [&] {
          regs_.B = mem_[regs_.HL()];
        };
    }

    {
        auto& LDSP = opcodes_[0x48];
        LDSP.opCode = 0x48;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,B";
        LDSP.work = [&] {
          regs_.C = regs_.B();
        };
    }

    {
        auto& LDSP = opcodes_[0x49];
        LDSP.opCode = 0x49;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,C";
        LDSP.work = [&] {
          regs_.C = regs_.C();
        };
    }

    {
        auto& LDSP = opcodes_[0x4A];
        LDSP.opCode = 0x4A;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,D";
        LDSP.work = [&] {
          regs_.C = regs_.D();
        };
    }

    {
        auto& LDSP = opcodes_[0x4B];
        LDSP.opCode = 0x4B;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,E";
        LDSP.work = [&] {
          regs_.C = regs_.E();
        };
    }

    {
        auto& LDSP = opcodes_[0x4C];
        LDSP.opCode = 0x4C;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,H";
        LDSP.work = [&] {
          regs_.C = regs_.H();
        };
    }

    {
        auto& LDSP = opcodes_[0x4D];
        LDSP.opCode = 0x4D;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD C,L";
        LDSP.work = [&] {
          regs_.C = regs_.L();
        };
    }

    {
        auto& LDSP = opcodes_[0x4E];
        LDSP.opCode = 0x4E;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD C,B";
        LDSP.work = [&] {
          regs_.C = mem_[regs_.HL()];
        };
    }

    {
        auto& LDSP = opcodes_[0x50];
        LDSP.opCode = 0x50;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,B";
        LDSP.work = [&] {
          regs_.D = regs_.B();
        };
    }

    {
        auto& LDSP = opcodes_[0x51];
        LDSP.opCode = 0x51;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,C";
        LDSP.work = [&] {
          regs_.D = regs_.C();
        };
    }

    {
        auto& LDSP = opcodes_[0x52];
        LDSP.opCode = 0x52;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,D";
        LDSP.work = [&] {
          regs_.D = regs_.D();
        };
    }

    {
        auto& LDSP = opcodes_[0x53];
        LDSP.opCode = 0x53;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,E";
        LDSP.work = [&] {
          regs_.D = regs_.E();
        };
    }

    {
        auto& LDSP = opcodes_[0x54];
        LDSP.opCode = 0x54;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,H";
        LDSP.work = [&] {
          regs_.D = regs_.H();
        };
    }

    {
        auto& LDSP = opcodes_[0x55];
        LDSP.opCode = 0x55;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "LD D,L";
        LDSP.work = [&] {
          regs_.D = regs_.L();
        };
    }

    {
        auto& LDSP = opcodes_[0x56];
        LDSP.opCode = 0x56;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "LD D,HL";
        LDSP.work = [&] {
          regs_.D = mem_[regs_.HL()];
        };
    }




    // XOR n
    // Logical exclusive OR n with register A, result in A

    // XOR A
    {
        auto& LDSP = opcodes_[0xAF];
        LDSP.opCode = 0xAF;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR A";
        LDSP.work = [&] {
          xor_a(regs_.A());
        };
    }

    // XOR B
    {
        auto& LDSP = opcodes_[0xA8];
        LDSP.opCode = 0xA8;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR B";
        LDSP.work = [&] {
          xor_a(regs_.B());
        };
    }

    // XOR C
    {
        auto& LDSP = opcodes_[0xA9];
        LDSP.opCode = 0xA9;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR C";
        LDSP.work = [&] {
          xor_a(regs_.C());
        };
    }

    // XOR D
    {
        auto& LDSP = opcodes_[0xAA];
        LDSP.opCode = 0xAA;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR D";
        LDSP.work = [&] {
          xor_a(regs_.D());
        };
    }

    // XOR E
    {
        auto& LDSP = opcodes_[0xAB];
        LDSP.opCode = 0xAB;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR E";
        LDSP.work = [&] {
          xor_a(regs_.E());
        };
    }

    // XOR H
    {
        auto& LDSP = opcodes_[0xAC];
        LDSP.opCode = 0xAC;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR H";
        LDSP.work = [&] {
          xor_a(regs_.H());
        };
    }

    // XOR L
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAD;
        LDSP.cyclesToComplete = 4;
        LDSP.name = "XOR L";
        LDSP.work = [&] {
          xor_a(regs_.L());
        };
    }

    // XOR HL
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAE;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "XOR HL";
        LDSP.work = [&] {
          xor_a(mem_[regs_.HL()]);
        };
    }

    // XOR #
    {
        auto& LDSP = opcodes_[0xAD];
        LDSP.opCode = 0xAE;
        LDSP.cyclesToComplete = 8;
        LDSP.name = "XOR HL";
        LDSP.work = [&] {
          xor_a(mem_[regs_.PC()]);
        };
    }
}

void OpCodes::executeOpcode(uint8_t opcode)
{
    opcodes_[opcode].work();
}

OpCode& OpCodes::getOpcode(uint8_t opcode)
{
    return opcodes_[opcode];
}

void OpCodes::resetFlags()
{
    regs_.Flag.resetAllFlags();
}

void OpCodes::setZ()
{
    regs_.Flag.setZ(true);
}

void OpCodes::xor_a(uint8_t val)
{
    resetFlags();
    regs_.A = (regs_.A() ^ val);
    if (regs_.A()==0) {
        setZ();
    }
}
