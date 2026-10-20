#include "cpu.h"

#include <stdio.h>

int main() {
    CPU cpu;

    cpu.pc = 0;
    cpu.halt = false;

    Memory memory;

    memory.memory[0] = 0x00;
    memory.memory[1] = 0x00;
    memory.memory[2] = 0x08;
    memory.memory[3] = 0x00;
    memory.memory[4] = 0x08;
    memory.memory[5] = 0xFF;
    memory.memory[6] = 0xF8;
    memory.memory[7] = 0x00;

    run(&cpu, &memory);

    printf("Done\n");
}