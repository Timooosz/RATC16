#include "cpu.h"

#include <stdio.h>

int main() {
    CPU cpu;

    cpu.pc = 0;
    cpu.halt = false;

    Memory memory;

    memory.memory[0] = 0x0000;
    memory.memory[1] = 0b1000100000000000;
    memory.memory[2] = 0x0000;
    memory.memory[3] = 0x0000;
    memory.memory[4] = 0xF000;

    run(&cpu, &memory);

    printf("Done\n");
}