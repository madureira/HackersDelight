#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdio.h>

#include "types.h"

#define BITS8 8

/**
 * Prints the binary representation of the least significant 8 bits of x.
 */
static inline void print_bits8(u32 x) {
    for (i32 i = BITS8 - 1; i >= 0; i--) {
        u32 mask = (u32)1u << i;
        putchar((x & mask) ? '1' : '0');
    }
}

/**
 * Prints the binary representation of a 32-bit unsigned integer with
 * underscores separating each nibble (4 bits).
 */
static inline void print_bits32(u32 v) {
    for (i32 i = 31; i >= 0; --i) {
        putchar((v >> i) & 1u ? '1' : '0');
        if (i % 4 == 0 && i != 0) {
            putchar('_');
        }
    }
}

/**
 * Prints the binary representation of the least significant 8 bits of x,
 * followed by a newline.
 */
static inline void println_bits8(u32 x) {
    print_bits8(x);
    putchar('\n');
}

/**
 * Prints the binary representation of a 32-bit unsigned integer with
 * underscores separating each nibble (4 bits), followed by a newline.
 */
static inline void println_bits32(u32 v) {
    print_bits32(v);
    putchar('\n');
}

#endif // UTILS_H
