#include "../includes/utils.h"

ui32 snoob(ui32 x) {
    ui32 smallest;
    ui32 ripple;
    ui32 ones;
                                    // x        = xxx0 1111 0000
    smallest = x & -x;              // smallest = 0000 0001 0000
    ripple = smallest + x;          // ripple   = xxx1 0000 0000
    ones = x ^ ripple;              // ones     = 0001 1111 0000
    ones = (ones >> 2) / smallest;  // ones     = 0000 0000 0011

    return ripple | ones;           // result   = xxx1 0000 0011
}

int main() {
    ui32 x = 0b01011100;
    printf("x in binary: ");
    print_bits8(x);

    ui32 y = snoob(x);
    printf("snoob(x) in binary: ");
    print_bits8(y);

    return 0;
}
