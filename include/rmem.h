#ifndef RMEM_H
#define RMEM_H

#include "types.h"

#define load(m) m->mdr = m->memory[m->mar] 

typedef struct mem_s {
    i16 memory[0x10000];
    u16 mar;
    u16 mdr;
} Memory;

#endif