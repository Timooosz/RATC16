#include "instructions.h"
#include "util.h"
#include <stdio.h>

void instruction_NOP(CPU *cpu) {
    printf("NOP\n");
}

void instruction_HLT(CPU *cpu) {
    printf("HLT\n");
    M_HLT(cpu);
}

void instruction_UNDEFINED(CPU *cpu) {
    printf("CPU PANIC, undefined instruction %#02x\n", OP(cpu->ir));
    M_HLT(cpu);
}

void (*const instructions[0x20])(CPU*) = {
    instruction_NOP, // 0x00
    instruction_UNDEFINED, // 0x01
    instruction_UNDEFINED, // 0x02
    instruction_UNDEFINED, // 0x03
    instruction_UNDEFINED, // 0x04
    instruction_UNDEFINED, // 0x05
    instruction_UNDEFINED, // 0x06
    instruction_UNDEFINED, // 0x07
    instruction_UNDEFINED, // 0x08
    instruction_UNDEFINED, // 0x09
    instruction_UNDEFINED, // 0x0A
    instruction_UNDEFINED, // 0x0B
    instruction_UNDEFINED, // 0x0C
    instruction_UNDEFINED, // 0x0D
    instruction_UNDEFINED, // 0x0E
    instruction_UNDEFINED, // 0x0F
    instruction_UNDEFINED, // 0x10
    instruction_UNDEFINED, // 0x11
    instruction_UNDEFINED, // 0x12
    instruction_UNDEFINED, // 0x13
    instruction_UNDEFINED, // 0x14
    instruction_UNDEFINED, // 0x15
    instruction_UNDEFINED, // 0x16
    instruction_UNDEFINED, // 0x17
    instruction_UNDEFINED, // 0x18
    instruction_UNDEFINED, // 0x19
    instruction_UNDEFINED, // 0x1A
    instruction_UNDEFINED, // 0x1B
    instruction_UNDEFINED, // 0x1C
    instruction_UNDEFINED, // 0x1D
    instruction_UNDEFINED, // 0x1E
    instruction_HLT  // 0x1F
};

void handle_instruction(CPU *cpu) {
    u8 operator = OP(cpu->ir);
    instructions[operator](cpu);
}