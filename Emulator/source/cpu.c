#include "cpu.h"
#include "instructions.h"
#include <stdio.h>

void run(CPU* cpu, Memory* memory) {
    bool halted = false;
    static int cycle = 0;

    printf("Running\n");

    while(!halted) {
        printf("Cycle %d, PC = %d\n", cycle, cpu->pc);
        CPU_IF(cpu, memory);
        CPU_EX(cpu);
        CPU_MEM(cpu, memory);
        CPU_WB(cpu);
        halted = cpu->halt;
    }
}

void CPU_IF(CPU* cpu, Memory* memory) {
    memory->mar = cpu->pc++;
    load(memory);
    cpu->ir = memory->mdr;
    printf("Fetched %#04x\n", cpu->ir);
}

void CPU_EX(CPU* cpu) {
    handle_instruction(cpu);
}

void CPU_MEM(CPU* cpu, Memory* memory) {

}

void CPU_WB(CPU* cpu) {

}