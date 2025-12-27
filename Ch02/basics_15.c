#include "../includes/utils.h"

static u32 avg_floor_ui32(u32 x, u32 y) {
    // floor((x + y) / 2) without overflow
    return (x & y) + ((x ^ y) >> 1);
}

static u32 avg_ceil_ui32(u32 x, u32 y) {
    // ceil((x | y) / 2) without overflow
    return (x | y) - ((x ^ y) >> 1);
}

static i32 avg_floor_i32(i32 x, i32 y) {
    // floor((x + y) / 2) without overflow (assumes arithmetic >>)
    return (x & y) + ((x ^ y) >> 1);
}

static i32 avg_ceil_i32(i32 x, i32 y) {
    // ceil((x + y) / 2) without overflow (assumes arithmetic >>)
    return (x | y) - ((x ^ y) >> 1);
}

static i32 avg_trunc_i32(i32 x, i32 y) {
    // Truncate average: (x + y) / 2 rounded toward 0, without overflow.
    // From the book:
    // t = (x & y) + ((x ^ y) >> 1);
    // t + (((uint)t >> 31) & (x ^ y));
    //
    // Explanation:
    // - t is the floor average.
    // - If t is negative (so x+y is negative) AND x+y is odd (LSB of x^y = 1),
    // add 1 to move floor toward 0.
    i32 t = (x & y) + ((x ^ y) >> 1);
    i32 corr = ((u32)t >> 31) & (x ^ y); // becomes 0 or 1
    return t + corr;
}

// Special case mentioned: x,y signed and known nonnegative.
static i32 avg_nonneg_i32_fast(i32 x, i32 y) {
    u32 sum = (u32)x + (u32)y; // wraps in unsigned (well-defined)
    return (i32)(sum >> 1);
}

// Special case: if x <= y, use x + ((y - x) >> 1) (floor average).
static i32 avg_floor_i32_ordered(i32 x, i32 y) {
    // Do (y - x) in int64_t to avoid potential signed overflow UB.
    i64 dx = (i64)y - (i64)x;      // nonnegative if x <= y
    return (i32)((i64)x + (dx >> 1));
}

static void demo_ui32(u32 x, u32 y) {
    u64 sum = (u64)x + (u64)y;
    u32 ref_floor = (u32)(sum / 2);
    u32 ref_ceil  = (u32)((sum + 1) / 2);

    u32 f1 = avg_floor_ui32(x, y);
    u32 c1 = avg_ceil_ui32(x, y);

    printf("UNSIGNED: x=%u (0x%08X), y=%u (0x%08X)\n", x, x, y, y);
    printf("  sum (u64) = %llu\n", (unsigned long long)sum);
    printf("  floor ref = %u, formula = %u%s\n", ref_floor, f1, (ref_floor == f1 ? "" : "  <-- MISMATCH"));
    printf("  ceil  ref = %u, formula = %u%s\n", ref_ceil,  c1, (ref_ceil  == c1 ? "" : "  <-- MISMATCH"));
    printf("\n");
}

static void demo_i32(i32 x, i32 y) {
    i64 sum = (i64)x + (i64)y;

    // Reference computations (no overflow due to int64_t):
    i32 ref_floor = (i32)((sum >= 0) ? (sum / 2) : -(((-sum) + 1) / 2)); // floor division by 2
    i32 ref_ceil  = (i32)((sum >= 0) ? ((sum + 1) / 2) : -(((-sum)) / 2)); // ceil division by 2

    // Trunc toward 0 reference:
    i32 ref_trunc = (i32)(sum / 2); // in C, int64_t / 2 truncs toward 0

    i32 f = avg_floor_i32(x, y);
    i32 c = avg_ceil_i32(x, y);
    i32 t = avg_trunc_i32(x, y);

    printf("SIGNED: x=%d (0x%08X), y=%d (0x%08X)\n", x, (u32)x, y, (u32)y);
    printf("  sum (i64) = %lld\n", (long long)sum);
    printf("  floor ref = %d, formula = %d%s\n", ref_floor, f, (ref_floor == f ? "" : "  <-- MISMATCH"));
    printf("  ceil  ref = %d, formula = %d%s\n", ref_ceil,  c, (ref_ceil  == c ? "" : "  <-- MISMATCH"));
    printf("  trunc ref = %d, formula = %d%s\n", ref_trunc, t, (ref_trunc == t ? "" : "  <-- MISMATCH"));

    // Show the two special cases quickly when they apply:
    if (x >= 0 && y >= 0) {
        i32 fast = avg_nonneg_i32_fast(x, y);
        printf("  nonneg fast (u >> 1) = %d\n", fast);
    }
    if (x <= y) {
        i32 ord = avg_floor_i32_ordered(x, y);
        printf("  ordered floor x + ((y - x) >> 1) = %d\n", ord);
    }
    printf("\n");
}

int main() {
    // Unsigned test cases (including overflow-prone sums)
    demo_ui32(0u, 1u);
    demo_ui32(1u, 2u);
    demo_ui32(0u, UINT32_MAX);
    demo_ui32(UINT32_MAX, UINT32_MAX);
    demo_ui32(UINT32_MAX, UINT32_MAX - 1u);
    demo_ui32(4000000000u, 4000000000u);

    printf("--------------------------------------------------------------\n\n");

    // Signed test cases (including extremes)
    demo_i32(-1, 0);                // average floor = -1, trunc = 0?
    demo_i32(-2, -1);
    demo_i32(-3, 2);
    demo_i32(INT32_MIN, INT32_MAX); // sum = -1
    demo_i32(INT32_MIN, INT32_MIN);
    demo_i32(INT32_MAX, INT32_MAX);
    demo_i32(10, 11);

    return 0;
}
