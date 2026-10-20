#include "cpu.h"
#include "instructions.h"
#include <stdio.h>

CPU makeCPU() {
    CPU cpu;
    cpu.zf = 0;
    cpu.nf = 0;
    cpu.cf = 0;
    cpu.halt = false;
    cpu.ir = 0;
    cpu.pc = 0;

    for (size_t i = 0; i < 8; i++) cpu.registers[i] = 0;

    return cpu;
}

void run(CPU* cpu, Memory* memory) {
    bool halted = false;

    printf("Running\n");

    while(!halted) {
        printf("PC = %d\n", cpu->pc);
        CPU_IF(cpu, memory);
        CPU_EX(cpu, memory);
        halted = cpu->halt;
        printf("r0 %#04x, r1 %#04x, r2 %#04x, r3 %#04x\nr4 %#04x, r5 %#04x, r6 %#04x, r7 %#04x\nZF %d, NF %d, CF %d\n", cpu->registers[0], cpu->registers[1], cpu->registers[2], cpu->registers[3], cpu->registers[4], cpu->registers[5], cpu->registers[6], cpu->registers[7], cpu->zf, cpu->nf, cpu->cf);
    }
}

void CPU_IF(CPU* cpu, Memory* memory) {
    memory->mar = cpu->pc++;
    load(memory);
    cpu->ir = (u16)memory->mdr << 8;
    memory->mar = cpu->pc++;
    load(memory);
    cpu->ir |= memory->mdr;
    printf("Fetched %#04x\n", cpu->ir);
}

void CPU_EX(CPU* cpu, Memory* memory) {
    handle_instruction(cpu, memory);
}