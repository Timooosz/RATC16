#ifndef CPU_H
#define CPU_H

#include <stdbool.h>
#include "rmem.h"

#define zf flags[0] // Zero flag
#define nf flags[1] // Negative flag
#define cf flags[2] // Carry flag

typedef struct cpu_s {
    i16 registers[8];
    u16 pc;
    u16 ir;
    bool flags[3];
    bool halt;
} CPU;

CPU makeCPU();

void run(CPU* cpu, Memory* memory);

void CPU_IF(CPU* cpu, Memory* memory);

void CPU_EX(CPU* cpu, Memory* memory);

#endif