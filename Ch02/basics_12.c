#include "../includes/utils.h"

int main() {
    u32 x = 0b01011100;

    printf("x in binary: ");
    print_bits8(x);

    u32 y = (((x | (x - 1u)) + 1u) & x);

    printf("(((x | (x - 1u)) + 1u) & x) in binary: ");
    print_bits8(y);

    y = ((x & -x) + x) & x;
    printf("((x & -x) + x) & x in binary: ");
    print_bits8(y);

    return 0;
}
