#ifndef RMEM_H
#define RMEM_H

#include "types.h"

#define load(m) m->mdr = m->memory[m->mar] 

typedef struct mem_s {
    u8 memory[0x10000];
    u16 mar;
    u8 mdr;
} Memory;

#endif