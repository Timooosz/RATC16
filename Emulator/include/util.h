#ifndef UTIL_H
#define UTIL_H

#define OP(n) (n >> 11) & 0b11111
#define RPARAM1(n) (n >> 8) & 0b111
#define RPARAM2(n) (n >> 5) & 0b111
#define RPARAM3(n) (n >> 2) & 0b111
#define IMM(n) n & 0xFF

static inline u16 read_u16(const u8 *memory, u16 address) {return ((u16)memory[address] << 8) | memory[address + 1];}

#endif