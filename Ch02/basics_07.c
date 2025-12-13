#include "../includes/utils.h"

int main() {
    ui32 x = 0b01011000;

    printf("x in binary: ");
    print_bits8(x);

    ui32 y = ~x & (x - 1);

    printf("~x & (x - 1) in binary: ");
    print_bits8(y);

    y = ~(x | -x);

    printf("~(x | -x) in binary: ");
    print_bits8(y);

    y = (x & -x) - 1;

    printf("(x & -x) - 1 in binary: ");
    print_bits8(y);

    return 0;
}
