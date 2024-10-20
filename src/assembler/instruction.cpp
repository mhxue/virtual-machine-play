#include "definitions.h"

struct Instruction
{
protected:
    int16_t data;
public:
    Instruction() {}
    Instruction(OPCode code) {
        int mask = 0b1111 << 12;
        data &= ~mask;
        data |= code << 12;
    }
};

struct TrapInstruction: Instruction {
    TrapInstruction(OPCode op_code, TrapCode trap_code): Instruction(op_code) {
        int mask = 0b1111;
        data &= ~mask;
        data |= trap_code;
    }
};

TrapCode parseTrapCode(std::string code) {
    std::unordered_map<std::string, TrapCode> map{
        {"TRAP_GETC", TRAP_GETC},
        {"TRAP_OUT", TRAP_OUT},
        {"TRAP_PUTS", TRAP_PUTS},
        {"TRAP_IN", TRAP_IN},
        {"TRAP_PUTSP", TRAP_PUTSP},
        {"TRAP_HALT", TRAP_HALT}
    };
    return map[code];
}