#include "cpu.h"
#include <stdio.h>

void run(CPU* cpu, Memory* memory) {
    bool running = true;
    static int cycle = 0;

    printf("Running\n");

    while(running) {
        printf("Cycle %d, PC = %d\n", cycle, cpu->pc);
        CPU_IF(cpu, memory);
        running = CPU_EX(cpu);
        CPU_MEM(cpu, memory);
        CPU_WB(cpu);
    }
}

void CPU_IF(CPU* cpu, Memory* memory) {
    memory->mar = cpu->pc++;
    load(memory);
    cpu->ir = memory->mdr;
    printf("Fetched %x\n", cpu->ir);
}

bool CPU_EX(CPU* cpu) {
    return (cpu->ir == 0xF000);
}

void CPU_MEM(CPU* cpu, Memory* memory) {

}

void CPU_WB(CPU* cpu) {

}