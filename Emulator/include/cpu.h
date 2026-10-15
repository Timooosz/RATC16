#ifndef CPU_H
#define CPU_H

#include <stdbool.h>
#include "rmem.h"

#define zf flags[0]
#define nf flags[1]
#define cf flags[2]
#define of flags[3]

typedef struct cpu_s {
    i16 reg[8];
    u16 pc;
    u16 ir;
    bool flags[4];
    bool halt;
} CPU;

void run(CPU* cpu, Memory* memory);

void CPU_IF(CPU* cpu, Memory* memory);

void CPU_EX(CPU* cpu);

void CPU_MEM(CPU* cpu, Memory* memory);

void CPU_WB(CPU* cpu);

#endif