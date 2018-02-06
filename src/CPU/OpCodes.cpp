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

    // LD n, nn
    // Put value nn into n

    {
        auto& opcode = opcodes_[0x01];
        opcode.opCode = 0x01;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD BC, nn";
        opcode.work = [&] {
          regs_.BC = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
          regs_.PC++;
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x11];
        opcode.opCode = 0x11;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD DE, nn";
        opcode.work = [&] {
          regs_.DE = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
          regs_.PC++;
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x21];
        opcode.opCode = 0x21;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD HL, nn";
        opcode.work = [&] {
          regs_.HL = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
          regs_.PC++;
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x31];
        opcode.opCode = 0x31;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD SP, nn";
        opcode.work = [&] {
          regs_.SP = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
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
        auto& opcode = opcodes_[0x06];
        opcode.opCode = 0x06;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD B,n";
        opcode.work = [&] {
          regs_.B = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x0E];
        opcode.opCode = 0x0E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD C,n";
        opcode.work = [&] {
          regs_.C = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x16];
        opcode.opCode = 0x16;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD D,n";
        opcode.work = [&] {
          regs_.D = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x1E];
        opcode.opCode = 0x1E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD E,n";
        opcode.work = [&] {
          regs_.E = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x26];
        opcode.opCode = 0x26;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD H,n";
        opcode.work = [&] {
          regs_.H = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x2E];
        opcode.opCode = 0x2E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD L,n";
        opcode.work = [&] {
          regs_.L = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    // LD r1, r2
    // put value r2 into r1
    // Use with: r1, r2 = A, B, C, D, E, H, L, (HL)
    {
        auto& opcode = opcodes_[0x7F];
        opcode.opCode = 0x7F;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,A";
        opcode.work = [&] {
          regs_.A = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x78];
        opcode.opCode = 0x78;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,B";
        opcode.work = [&] {
          regs_.A = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x79];
        opcode.opCode = 0x79;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,C";
        opcode.work = [&] {
          regs_.A = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x7A];
        opcode.opCode = 0x7A;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,D";
        opcode.work = [&] {
          regs_.A = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x7B];
        opcode.opCode = 0x7B;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,E";
        opcode.work = [&] {
          regs_.A = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x7C];
        opcode.opCode = 0x7C;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,H";
        opcode.work = [&] {
          regs_.A = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x7D];
        opcode.opCode = 0x7D;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD A,L";
        opcode.work = [&] {
          regs_.A = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x0A];
        opcode.opCode = 0x0A;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD A,(BC)";
        opcode.work = [&] {
          regs_.A = mem_[regs_.BC()];
        };
    }

    {
        auto& opcode = opcodes_[0x1A];
        opcode.opCode = 0x1A;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD A,(DE)";
        opcode.work = [&] {
          regs_.A = mem_[regs_.DE()];
        };
    }

    {
        auto& opcode = opcodes_[0x7E];
        opcode.opCode = 0x7E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD A, (HL)";
        opcode.work = [&] {
          regs_.A = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0xFA];
        opcode.opCode = 0xFA;
        opcode.cyclesToComplete = 16;
        opcode.name = "LD A,(NN)";
        opcode.work = [&] {
          uint16_t memAddr = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
          regs_.A = mem_[memAddr];
          // increment PC because this operation takes two bytes from mem
          regs_.PC++;
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x3E];
        opcode.opCode = 0x3E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD A,#";
        opcode.work = [&] {
          regs_.A = mem_[regs_.PC()];
          regs_.PC++;
        };
    }

    {
        auto& opcode = opcodes_[0x40];
        opcode.opCode = 0x40;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,B";
        opcode.work = [&] {
          regs_.B = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x41];
        opcode.opCode = 0x41;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,C";
        opcode.work = [&] {
          regs_.B = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x42];
        opcode.opCode = 0x42;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,D";
        opcode.work = [&] {
          regs_.B = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x43];
        opcode.opCode = 0x43;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,E";
        opcode.work = [&] {
          regs_.B = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x44];
        opcode.opCode = 0x44;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,H";
        opcode.work = [&] {
          regs_.B = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x45];
        opcode.opCode = 0x45;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B,L";
        opcode.work = [&] {
          regs_.B = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x46];
        opcode.opCode = 0x46;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD B,HL";
        opcode.work = [&] {
          regs_.B = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0x48];
        opcode.opCode = 0x48;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,B";
        opcode.work = [&] {
          regs_.C = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x49];
        opcode.opCode = 0x49;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,C";
        opcode.work = [&] {
          regs_.C = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x4A];
        opcode.opCode = 0x4A;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,D";
        opcode.work = [&] {
          regs_.C = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x4B];
        opcode.opCode = 0x4B;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,E";
        opcode.work = [&] {
          regs_.C = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x4C];
        opcode.opCode = 0x4C;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,H";
        opcode.work = [&] {
          regs_.C = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x4D];
        opcode.opCode = 0x4D;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C,L";
        opcode.work = [&] {
          regs_.C = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x4E];
        opcode.opCode = 0x4E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD C,B";
        opcode.work = [&] {
          regs_.C = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0x50];
        opcode.opCode = 0x50;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,B";
        opcode.work = [&] {
          regs_.D = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x51];
        opcode.opCode = 0x51;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,C";
        opcode.work = [&] {
          regs_.D = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x52];
        opcode.opCode = 0x52;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,D";
        opcode.work = [&] {
          regs_.D = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x53];
        opcode.opCode = 0x53;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,E";
        opcode.work = [&] {
          regs_.D = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x54];
        opcode.opCode = 0x54;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,H";
        opcode.work = [&] {
          regs_.D = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x55];
        opcode.opCode = 0x55;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D,L";
        opcode.work = [&] {
          regs_.D = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x56];
        opcode.opCode = 0x56;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD D,HL";
        opcode.work = [&] {
          regs_.D = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0x58];
        opcode.opCode = 0x58;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,B";
        opcode.work = [&] {
          regs_.E = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x59];
        opcode.opCode = 0x59;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,C";
        opcode.work = [&] {
          regs_.E = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x5A];
        opcode.opCode = 0x5A;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,D";
        opcode.work = [&] {
          regs_.E = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x5B];
        opcode.opCode = 0x5B;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,E";
        opcode.work = [&] {
          regs_.E = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x5C];
        opcode.opCode = 0x5C;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,H";
        opcode.work = [&] {
          regs_.E = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x5D];
        opcode.opCode = 0x5D;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E,L";
        opcode.work = [&] {
          regs_.E = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x5E];
        opcode.opCode = 0x5E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD E,(HL)";
        opcode.work = [&] {
          regs_.E = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0x60];
        opcode.opCode = 0x60;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,B";
        opcode.work = [&] {
          regs_.H = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x61];
        opcode.opCode = 0x61;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,C";
        opcode.work = [&] {
          regs_.H = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x62];
        opcode.opCode = 0x62;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,D";
        opcode.work = [&] {
          regs_.H = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x63];
        opcode.opCode = 0x63;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,E";
        opcode.work = [&] {
          regs_.H = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x64];
        opcode.opCode = 0x64;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,H";
        opcode.work = [&] {
          regs_.H = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x65];
        opcode.opCode = 0x65;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,L";
        opcode.work = [&] {
          regs_.H = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x66];
        opcode.opCode = 0x66;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H,(HL)";
        opcode.work = [&] {
          regs_.H = mem_[regs_.B()];
        };
    }

    {
        auto& opcode = opcodes_[0x68];
        opcode.opCode = 0x68;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,B";
        opcode.work = [&] {
          regs_.L = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x69];
        opcode.opCode = 0x69;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,C";
        opcode.work = [&] {
          regs_.L = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x6A];
        opcode.opCode = 0x6A;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,D";
        opcode.work = [&] {
          regs_.L = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x6B];
        opcode.opCode = 0x6B;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,E";
        opcode.work = [&] {
          regs_.L = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x6C];
        opcode.opCode = 0x6C;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,C";
        opcode.work = [&] {
          regs_.L = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x6D];
        opcode.opCode = 0x6D;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L,L";
        opcode.work = [&] {
          regs_.L = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x6E];
        opcode.opCode = 0x6E;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD L,(HL)";
        opcode.work = [&] {
          regs_.L = mem_[regs_.HL()];
        };
    }

    {
        auto& opcode = opcodes_[0x70];
        opcode.opCode = 0x70;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), B";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.B();
        };
    }

    {
        auto& opcode = opcodes_[0x71];
        opcode.opCode = 0x71;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), C";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.C();
        };
    }

    {
        auto& opcode = opcodes_[0x72];
        opcode.opCode = 0x72;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), D";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.D();
        };
    }

    {
        auto& opcode = opcodes_[0x73];
        opcode.opCode = 0x73;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), E";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.E();
        };
    }

    {
        auto& opcode = opcodes_[0x74];
        opcode.opCode = 0x74;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), H";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.H();
        };
    }

    {
        auto& opcode = opcodes_[0x75];
        opcode.opCode = 0x75;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (HL), L";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.L();
        };
    }

    {
        auto& opcode = opcodes_[0x36];
        opcode.opCode = 0x36;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD (HL), n";
        opcode.work = [&] {
          regs_.PC++;
          mem_[regs_.HL()] = mem_[regs_.PC()];
        };
    }


    // XOR n
    // Logical exclusive OR n with register A, result in A

    // XOR A
    {
        auto& opcode = opcodes_[0xAF];
        opcode.opCode = 0xAF;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR A";
        opcode.work = [&] {
          xor_a(regs_.A());
        };
    }

    // XOR B
    {
        auto& opcode = opcodes_[0xA8];
        opcode.opCode = 0xA8;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR B";
        opcode.work = [&] {
          xor_a(regs_.B());
        };
    }

    // XOR C
    {
        auto& opcode = opcodes_[0xA9];
        opcode.opCode = 0xA9;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR C";
        opcode.work = [&] {
          xor_a(regs_.C());
        };
    }

    // XOR D
    {
        auto& opcode = opcodes_[0xAA];
        opcode.opCode = 0xAA;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR D";
        opcode.work = [&] {
          xor_a(regs_.D());
        };
    }

    // XOR E
    {
        auto& opcode = opcodes_[0xAB];
        opcode.opCode = 0xAB;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR E";
        opcode.work = [&] {
          xor_a(regs_.E());
        };
    }

    // XOR H
    {
        auto& opcode = opcodes_[0xAC];
        opcode.opCode = 0xAC;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR H";
        opcode.work = [&] {
          xor_a(regs_.H());
        };
    }

    // XOR L
    {
        auto& opcode = opcodes_[0xAD];
        opcode.opCode = 0xAD;
        opcode.cyclesToComplete = 4;
        opcode.name = "XOR L";
        opcode.work = [&] {
          xor_a(regs_.L());
        };
    }

    // XOR HL
    {
        auto& opcode = opcodes_[0xAD];
        opcode.opCode = 0xAE;
        opcode.cyclesToComplete = 8;
        opcode.name = "XOR HL";
        opcode.work = [&] {
          xor_a(mem_[regs_.HL()]);
        };
    }

    // XOR #
    {
        auto& opcode = opcodes_[0xAD];
        opcode.opCode = 0xAE;
        opcode.cyclesToComplete = 8;
        opcode.name = "XOR HL";
        opcode.work = [&] {
          xor_a(mem_[regs_.PC()]);
        };
    }

    // The following is out of order

    {
        auto& opcode = opcodes_[0x32];
        opcode.opCode = 0x32;
        opcode.cyclesToComplete = 8;
        opcode.name = "LDD (HL-),A";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.A();
          regs_.HL--;
          printf("HL is: %x \n", regs_.HL());
        };
    }

    {
        auto& opcode = opcodes_[0xCB];
        opcode.opCode = 0xCB;
        opcode.cyclesToComplete = 8;
        opcode.name = "Bit Opcode";
        opcode.work = [&] {
            uint8_t bitOpcode = mem_[regs_.PC()];
            executeOpcodes(bitOpcode);
            regs_.PC++;
        };
    }

    // JR CC,N
    // Description:
    // If following condition is true then add n to current address and jump to it:
    //
    // Use with:
    // n = one byte signed immediate value
    // cc = NZ, Jump if Z flag is reset.
    // cc=Z, JumpifZflagisset.
    // cc = NC, Jump if C flag is reset.
    // cc=C, JumpifCflagisset.
    {
        auto& opcode = opcodes_[0x20];
        opcode.opCode = 0x20;
        opcode.cyclesToComplete = 8;
        opcode.name = "JR NZ, *";
        opcode.work = [&] {
          bool zeroFlag = regs_.Flag.Z();
          if (!regs_.Flag.Z())
          {
              auto n = (int8_t)mem_[regs_.PC()];
              // Jump
              regs_.PC = regs_.PC() + n;
              std::printf("Jump to %x\n", regs_.PC() + 1);
          }
          else
          {
              std::cout << "no jump" << std::endl;
          }
          regs_.PC++;
        };
    }

    // LD (n), A
    // Put a into memory address 0xFF00 + n
    // n = one byt immediate value
    {
        auto& opcode = opcodes_[0xE0];
        opcode.opCode = 0xE0;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD (N),A";
        opcode.work = [&] {
          mem_[0xFF00 + mem_[regs_.PC()]] = regs_.A();
          regs_.PC++;
        };
    }

    // LD (C),A
    // Puts A into address 0xFF00 + register C
    {
        auto& opcode = opcodes_[0xE2];
        opcode.opCode = 0xE2;
        opcode.cyclesToComplete = 12;
        opcode.name = "LD (C),A";
        opcode.work = [&] {
          mem_[0xFF00 + regs_.C()] = regs_.A();
        };
    }

    // INC N
    // Increment register
    // Flags affected:
    // Z - set if result is zero
    // N - reset.
    // H - Set if carry from bit 3
    // C - Not affected
    {
        auto& opcode = opcodes_[0x3C];
        opcode.opCode = 0x3C;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC A";
        opcode.work = [&] {
         regs_.A = incrementRegister(regs_.A());
        };
    }

    {
        auto& opcode = opcodes_[0x04];
        opcode.opCode = 0x04;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC B";
        opcode.work = [&] {
          regs_.B = incrementRegister(regs_.B());
        };
    }

    {
        auto& opcode = opcodes_[0x0C];
        opcode.opCode = 0x0C;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC C";
        opcode.work = [&] {
          regs_.C = incrementRegister(regs_.C());
        };
    }

    {
        auto& opcode = opcodes_[0x14];
        opcode.opCode = 0x14;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC D";
        opcode.work = [&] {
          regs_.D = incrementRegister(regs_.D());
        };
    }

    {
        auto& opcode = opcodes_[0x1C];
        opcode.opCode = 0x1C;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC E";
        opcode.work = [&] {
          regs_.E = incrementRegister(regs_.E());
        };
    }

    {
        auto& opcode = opcodes_[0x24];
        opcode.opCode = 0x24;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC H";
        opcode.work = [&] {
          regs_.H = incrementRegister(regs_.H());
        };
    }

    {
        auto& opcode = opcodes_[0x2C];
        opcode.opCode = 0x2C;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC L";
        opcode.work = [&] {
          regs_.L = incrementRegister(regs_.L());
        };
    }

    {
        auto& opcode = opcodes_[0x34];
        opcode.opCode = 0x34;
        opcode.cyclesToComplete = 4;
        opcode.name = "INC (HL)";
        opcode.work = [&] {
          regs_.HL = incrementRegister(mem_[regs_.HL()]);
        };
    }

    // LD n, A
    // Description:
    // Put value A into N

    {
        auto& opcode = opcodes_[0x47];
        opcode.opCode = 0x47;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD B, A";
        opcode.work = [&] {
          regs_.B = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x4F];
        opcode.opCode = 0x4F;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD C, A";
        opcode.work = [&] {
          regs_.C = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x57];
        opcode.opCode = 0x57;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD D, A";
        opcode.work = [&] {
          regs_.D = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x5F];
        opcode.opCode = 0x5F;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD E, A";
        opcode.work = [&] {
          regs_.E = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x67];
        opcode.opCode = 0x67;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD H, A";
        opcode.work = [&] {
          regs_.H = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x6F];
        opcode.opCode = 0x6F;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD L, A";
        opcode.work = [&] {
          regs_.L = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x02];
        opcode.opCode = 0x02;
        opcode.cyclesToComplete = 8;
        opcode.name = "LD (BC), A";
        opcode.work = [&] {
          mem_[regs_.BC()] = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x12];
        opcode.opCode = 0x12;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD (DE), A";
        opcode.work = [&] {
          mem_[regs_.DE()] = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0x77];
        opcode.opCode = 0x77;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD (HL), A";
        opcode.work = [&] {
          mem_[regs_.HL()] = regs_.A();
        };
    }

    {
        auto& opcode = opcodes_[0xEA];
        opcode.opCode = 0xEA;
        opcode.cyclesToComplete = 4;
        opcode.name = "LD (NN), A";
        opcode.work = [&] {
          uint8_t low = mem_[regs_.PC()];
          regs_.PC++;
          uint8_t high = mem_[regs_.PC()];
          regs_.PC++;
          uint16_t loc = (high << 8) | low;
          mem_[regs_.DE()] = regs_.A();
        };
    }

    // Calls

    // CALL nn
    // Push address of next instruction onto stack and then jump to address nn
    {
        auto& opcode = opcodes_[0xCD];
        opcode.opCode = 0xCD;
        opcode.cyclesToComplete = 12;
        opcode.name = "CALL, nn";
        opcode.work = [&] {
          uint16_t address = (mem_[regs_.PC()] | mem_[regs_.PC()+1] << 8);
          regs_.PC++;
          regs_.PC++;
          pushOntoStack(regs_.PC());
          regs_.PC = address;
        };
    }

    // PUSH nn
    // Push register pair nn onto stack, decrement Stack Pointer (SP) twice

    {
        auto& opcode = opcodes_[0xF5];
        opcode.opCode = 0xF5;
        opcode.cyclesToComplete = 16;
        opcode.name = "PUSH AF";
        opcode.work = [&] {
          pushOntoStack(regs_.AF());
        };
    }

    {
        auto& opcode = opcodes_[0xC5];
        opcode.opCode = 0xC5;
        opcode.cyclesToComplete = 16;
        opcode.name = "PUSH BC";
        opcode.work = [&] {
          pushOntoStack(regs_.BC());
        };
    }

    {
        auto& opcode = opcodes_[0xD5];
        opcode.opCode = 0xD5;
        opcode.cyclesToComplete = 16;
        opcode.name = "PUSH DE";
        opcode.work = [&] {
          pushOntoStack(regs_.DE());
        };
    }

    {
        auto& opcode = opcodes_[0xE5];
        opcode.opCode = 0xE5;
        opcode.cyclesToComplete = 16;
        opcode.name = "PUSH HL";
        opcode.work = [&] {
          pushOntoStack(regs_.HL());
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

void OpCodes::executeOpcodes(uint8_t bitOpcode)
{

    switch (bitOpcode) {
    // BIT 7, H
    case 0x7c:
    {
        bit(regs_.H(), 7);
        std::printf("reg.h = %x\n", regs_.H());
        break;
    }
    default:
        std::printf("BitOpCode %X is not implemented\n", bitOpcode);
        break;
    }


}
bool OpCodes::bitSetInReg(int regVal, int bitPos)
{
    int mask = 1;
    mask = mask << bitPos;
    return regVal & mask;
}

void OpCodes::bit(int regVal, int bitPos)
{
    // If the bit value is 0 the Z flag is set

    if (bitSetInReg(regVal, bitPos))
    {
        regs_.Flag.setZ(false);
    }
    else
    {
        regs_.Flag.setZ(true);
    }
    // Flag N is reset
    regs_.Flag.setN(false);
    regs_.Flag.setH(true);
}

uint8_t OpCodes::incrementRegister(uint8_t regVal) const
{
    // Set half-carry flag
    regs_.Flag.setH(((((regVal & 0x0F)) + (1)) & 0x10) == 0x10);
    regVal++;

    if (regVal == 0)
    {
        regs_.Flag.setZ(true);
    }
    regs_.Flag.setN(false);
    return  regVal;
}

// Push address onto stack and decrement stack pointer
// as the stacks grows downward
// @ SP - 1 = high byte
// @ SP - 2 == low byte
void OpCodes::pushOntoStack(uint16_t address)
{
    regs_.SP--;
    mem_[regs_.SP()] = address >> 8;
    regs_.SP--;
    mem_[regs_.SP()] = address;
    std::printf("pushOntoStack: push address %X at SP(%X), SP-1=%X SP-2=%X\n", address, regs_.SP() + 1,  mem_[regs_.SP() + 1], mem_[regs_.SP()]);
}

