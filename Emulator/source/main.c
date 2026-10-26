#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>

#define MEM(x) memory.memory[x]

int main(int argc, char **argv) {

    if (argc != 2) return 1;

    CPU cpu = makeCPU();

    Memory memory = makeMemory();

    FILE *fptr;
    fptr = fopen(argv[1], "rb");

    if (fptr == NULL) return 2;

    size_t bytes_read = fread(memory.memory, 1, sizeof memory.memory, fptr);
    if (ferror(fptr)) {
        fclose(fptr);
        return 3;
    }

    run(&cpu, &memory);

    printf("Done\n");

    fclose(fptr);

    return 0;
}