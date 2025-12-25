#include "../includes/utils.h"

static inline i32 abs_xor_sub(i32 x) {
    // y = x >> 31 (arithmetic right shift): y is 0 for x >= 0, -1 for x < 0
    i32 y = x >> 31;
    return (x ^ y) - y;
}

static inline i32 abs_add_xor(i32 x) {
    i32 y = x >> 31;
    return (x + y) ^ y;
}

static inline i32 abs_sub_2x_and_y(i32 x) {
    i32 y = x >> 31;
    return x - ((x << 1) & y);
}

static inline i32 nabs_y_minus_xor(i32 x) {
    i32 y = x >> 31;
    return y - (x ^ y);
}

static inline i32 nabs_y_minus_x_xor(i32 x) {
    i32 y = x >> 31;
    return (y - x) ^ y;
}

static inline i32 nabs_2x_and_y_minus_x(i32 x) {
    i32 y = x >> 31;
    return ((x << 1) & y) - x;
}

static inline i32 abs_mul_pm1(i32 x) {
    // ((x >> 30) | 1) is +1 for x>=0 and -1 for x<0 (for typical 32-bit arithmetic shift)
    return ((x >> 30) | 1) * x;
}

int main() {
    // Test values, including the tricky INT32_MIN case.
    // NOTE: abs(INT32_MIN) overflows for int32_t (same issue as standard abs()).
    i32 tests[] = { 0, 1, -1, 7, -7, 123456, -123456, INT32_MAX, INT32_MIN };

    printf("%12s | %12s %12s %12s | %12s %12s %12s | %12s\n",
           "x", "abs1", "abs2", "abs3", "nabs1", "nabs2", "nabs3", "abs_mul");

    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        i32 x = tests[i];
        i32 abs1 = abs_xor_sub(x);
        i32 abs2 = abs_add_xor(x);
        i32 abs3 = abs_sub_2x_and_y(x);

        i32 nabs1 = nabs_y_minus_xor(x);
        i32 nabs2 = nabs_y_minus_x_xor(x);
        i32 nabs3 = nabs_2x_and_y_minus_x(x);

        i32 abs_mul = abs_mul_pm1(x);

        printf("%12d | %12d %12d %12d | %12d %12d %12d | %12d\n",
               x, abs1, abs2, abs3, nabs1, nabs2, nabs3, abs_mul);
    }

    printf("\nNotes:\n");
    printf("1) These formulas assume arithmetic right shift for signed int32_t (common on modern CPUs).\n");
    printf("2) abs(INT32_MIN) cannot be represented in int32_t, so it overflows (same caveat as C's abs()).\n");

    return 0;
}
