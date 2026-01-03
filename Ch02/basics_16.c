#include "../includes/utils.h"

// Portable reference: sign-extend low 8 bits (bit 7 is sign)
static i32 sx8_ref(u32 x) {
    u32 low = x & 0xFFu;

    if (low & 0x80u) {
        // Negative number: fill upper bits with 1s
        return (i32)(low | ~0xFFu);
    }

    return (i32)low;
}

// "Standard" method (common on 2's complement machines):
// shift left logical then shift right signed.
// Note: right shift of negative signed is implementation-defined in C.
static i32 sx8_shift(u32 x) {
    return (i32)((((i32)(x << 24)) >> 24));
}

// HD #1: ((x + 0x80) & 0xFF) - 0x80
static i32 sx8_hd1(u32 x) {
    u32 y = (x + 0x80u) & 0xFFu;
    return (i32)(y - 0x80u);
}

// HD #2: ((x & 0xFF) ^ 0x80) - 0x80
static i32 sx8_hd2(u32 x) {
    u32 y = ((x & 0xFFu) ^ 0x80);
    return (i32)(y - 0x80u);
}

// HD #3: (x & 0x7F) - (x & 0x80)
static i32 sx8_hd3(u32 x) {
    u32 y = (x & 0x7Fu) - (x & 0x80u);
    return (i32)y;
}

static void test(u32 x) {
    i32 ref = sx8_ref(x);
    i32 sh  = sx8_shift(x);
    i32 hd1 = sx8_hd1(x);
    i32 hd2 = sx8_hd2(x);
    i32 hd3 = sx8_hd3(x);

    printf("x = 0x%08X (", (unsigned)x);
    print_bits32(x);
    printf(")\n");

    printf("  ref  : %11d\n", (int)ref);
    printf("  shift: %11d %s\n", (int)sh,  (sh  == ref) ? "OK" : "DIFF");
    printf("  hd1  : %11d %s\n", (int)hd1, (hd1 == ref) ? "OK" : "DIFF");
    printf("  hd2  : %11d %s\n", (int)hd2, (hd2 == ref) ? "OK" : "DIFF");
    printf("  hd3  : %11d %s\n", (int)hd3, (hd3 == ref) ? "OK" : "DIFF");
    puts("");
}

int main() {
    u32 tests[] = {
        0x00000000u,
        0x00000001u,
        0x0000007Fu,
        0x00000080u,
        0x00000081u,
        0x000000FFu,
        0x12345680u,
        0xABCDEF7Fu,
        0xFFFFFFFFu,
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        test(tests[i]);
    }

    return 0;
}
