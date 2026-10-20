#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

#define M_HLT(cpu) cpu->halt = true

void instruction_NOP(CPU *cpu, Memory*);

void instruction_LOD_I(CPU *cpu, Memory*);

void instruction_HLT(CPU *cpu, Memory*);

void instruction_UNDEFINED(CPU *cpu, Memory*);

extern void (*const instructions[0x20])(CPU*, Memory*);

void handle_instruction(CPU *cpu, Memory *memory);

#endif