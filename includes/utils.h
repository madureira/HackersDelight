#include <stdio.h>
#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;
typedef long double f128;

typedef unsigned char uchar;

/**
 * Prints the binary representation of the least significant 8 bits of x.
 */
void print_bits8(u32 x) {
    i32 total_bits = 8;
    for (i32 i = total_bits - 1; i >= 0; i--) {
        u32 mask = (u32)1u << i;
        putchar((x & mask) ? '1' : '0');
    }
    printf("\n");
}
