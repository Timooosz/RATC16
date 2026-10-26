#include "instructions.h"
#include "util.h"
#include <stdio.h>

void instruction_NOP(CPU *cpu, Memory *memory) {
    printf("NOP\n");
}

void instruction_LDI_I(CPU *cpu, Memory *memory) {
    printf("LDI (I)\n");
    u8 reg = RPARAM1(cpu->ir);
    printf("r%d <- %#02x\n", reg, IMM(cpu->ir));
    cpu->registers[reg] = IMM(cpu->ir);
    cpu->zf = (cpu->registers[reg] == 0);
    cpu->nf = 0;
    cpu->cf = 0;
}

void instruction_LOD_I(CPU *cpu, Memory *memory) {
    printf("LOD (I)\n");
    u8 dst = RPARAM1(cpu->ir);
    u8 src = IMM(cpu->ir);
    cpu->registers[dst] = read_u16(memory->memory, src);
    printf("r%d <- @%#02x: %#04x\n", dst, src, cpu->registers[dst]);
    cpu->zf = (cpu->registers[dst] == 0);
    cpu->nf = ((cpu->registers[dst] >> 15) & 1 == 1);
    cpu->cf = 0;
}

void instruction_LOD_R(CPU *cpu, Memory* memory) {
    printf("LOD (R)\n");
    u8 dst = RPARAM1(cpu->ir);
    u8 src = RPARAM2(cpu->ir);
    i16 src_addr = cpu->registers[src];
    cpu->registers[dst] = read_u16(memory->memory, src_addr);
    printf("r%d <- @r%d (%#02x): %#04x\n", dst, src, src_addr, cpu->registers[dst]);
    cpu->zf = (cpu->registers[dst] == 0);
    cpu->nf = ((cpu->registers[dst] >> 15) & 1 == 1);
    cpu->cf = 0;
}


void instruction_STR_I(CPU *cpu, Memory *memory) {
    printf("STR (I)\n");
    u8 src = RPARAM1(cpu->ir);
    u8 dst = IMM(cpu->ir);
    printf("r%d: %#04x -> %#02x\n", src, cpu->registers[src], dst);
    write_u16(memory->memory, dst, cpu->registers[src]);
}

void instruction_STR_R(CPU *cpu, Memory *memory) {
    printf("STR (R)\n");
    u8 src = RPARAM1(cpu->ir);
    u8 dst = RPARAM2(cpu->ir);
    printf("r%d: %#04x -> r%d: %#04x\n", src, cpu->registers[src], dst, cpu->registers[dst]);
    write_u16(memory->memory, cpu->registers[dst], cpu->registers[src]);
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
    instruction_LDI_I, // 0x01
    instruction_LOD_I, // 0x02
    instruction_LOD_R, // 0x03
    instruction_STR_I, // 0x04
    instruction_STR_R, // 0x05
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