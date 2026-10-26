#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

#define M_HLT(cpu) cpu->halt = true

void instruction_NOP(CPU *cpu, Memory *memory);

void instruction_LDI_I(CPU *cpu, Memory *memory);
void instruction_LOD_I(CPU *cpu, Memory *memory);
void instruction_LOD_R(CPU *cpu, Memory *memory);

void instruction_STR_I(CPU *cpu, Memory *memory);
void instruction_STR_R(CPU *cpu, Memory *memory);

void instruction_HLT(CPU *cpu, Memory *memory);

void instruction_UNDEFINED(CPU *cpu, Memory *memory);

extern void (*const instructions[0x20])(CPU*, Memory *memory);

void handle_instruction(CPU *cpu, Memory *memory);

#endif