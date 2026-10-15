#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

#define M_HLT(cpu) cpu->halt = true

void instruction_NOP(CPU *cpu);

void instruction_HLT(CPU *cpu);

void instruction_UNDEFINED(CPU *cpu);

extern void (*const instructions[0x20])(CPU*);

void handle_instruction(CPU *cpu);

#endif