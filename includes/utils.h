#include <stdio.h>
#include <stdint.h>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float float32;
typedef double float64;
typedef long double float128;

typedef unsigned char uchar;

/**
 * Prints the binary representation of the least significant 8 bits of x.
 */
void print_bits8(uint32 x) {
    int32 total_bits = 8;
    for (int32 i = total_bits - 1; i >= 0; i--) {
        uint32 mask = 1u << i;
        putchar((x & mask) ? '1' : '0');
    }
    printf("\n");
}
