#include "cpu.h"

#include <stdio.h>

int main() {
    CPU cpu = makeCPU();

    Memory memory = makeMemory();

    memory.memory[0] = 0x08; memory.memory[1] = 0xAB; // LDI 0 #0xAB
    memory.memory[2] = 0x1C; memory.memory[3] = 0x00; // LOD 4 0
    memory.memory[4] = 0xF8; memory.memory[5] = 0x00; // 
    memory.memory[0xAB] = 0x12; memory.memory[0xAC] = 0x34;

    run(&cpu, &memory);

    printf("Done\n");
}