#ifndef UTIL_H
#define UTIL_H

#define OP(n) (n >> 11) & 0b11111
#define RPARAM1(n) (n >> 8) & 0b111
#define RPARAM2(n) (n >> 5) & 0b111
#define RPARAM3(n) (n >> 2) & 0b111
#define IMM(n) n & 0xFF

#endif