#include <cstdint>
#include <iostream>

#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];

enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT
};

uint16_t reg[R_COUNT];

enum OPCode
{
    OP_BR = 0, /* branch */
    OP_ADD = 1,    /* add  */
    OP_LD = 2,     /* load */
    OP_ST = 3,     /* store */
    OP_JSR = 4,    /* jump register */
    OP_AND = 5,    /* bitwise and */
    OP_LDR = 6,    /* load register */
    OP_STR = 7,    /* store register */
    OP_RTI = 8,    /* unused */
    OP_NOT = 9,    /* bitwise not */
    OP_LDI = 10,    /* load indirect */
    OP_STI = 11,    /* store indirect */
    OP_JMP = 12,    /* jump */
    OP_RES = 13,    /* reserved (unused) */
    OP_LEA = 14,    /* load effective address */
    OP_TRAP = 15   /* execute trap */
};

enum
{
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

enum TrapCode
{
    TRAP_GETC = 0x20,  /* get character from keyboard, not echoed onto the terminal */
    TRAP_OUT = 0x21,   /* output a character */
    TRAP_PUTS = 0x22,  /* output a word string */
    TRAP_IN = 0x23,    /* get character from keyboard, echoed onto the terminal */
    TRAP_PUTSP = 0x24, /* output a byte string */
    TRAP_HALT = 0x25   /* halt the program */
};

TrapCode parseTrapCode(std::string code);