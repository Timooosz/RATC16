#include "instructions.h"
#include "util.h"
#include <stdio.h>

void instruction_NOP(CPU *cpu, Memory *memory) {
    printf("NOP\n");
}

void instruction_LOD_I(CPU *cpu, Memory *memory) {
    printf("LOD (I)\n");
    u8 reg = RPARAM1(cpu->ir);
    printf("r%d <- %#02x\n", reg, IMM(cpu->ir));
    cpu->registers[reg] = IMM(cpu->ir);
    cpu->zf = (cpu->registers[reg] == 0);
    cpu->nf = 0;
    cpu->cf = 0;
}

void instruction_HLT(CPU *cpu, Memory *memory) {
    printf("HLT\n");
    M_HLT(cpu);
}

void instruction_UNDEFINED(CPU *cpu, Memory *memory) {
    printf("CPU PANIC, undefined instruction %#02x\n", OP(cpu->ir));
    M_HLT(cpu);
}

void (*const instructions[0x20])(CPU*, Memory *memory) = {
    instruction_NOP, // 0x00
    instruction_LOD_I, // 0x01
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

void handle_instruction(CPU *cpu, Memory *memory) {
    u8 operator = OP(cpu->ir);
    instructions[operator](cpu, memory);
}