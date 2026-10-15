#ifndef UTIL_H
#define UTIL_H

#define OP(n) (n >> 11) & 0b11111
#define REG(n) (n >> 8) & 0b111
#define ARG(n) n & 0xF

#endif