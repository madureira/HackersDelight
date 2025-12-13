#include "../includes/utils.h"

int main() {
    ui32 x = 0b01011000;

    printf("x in binary: ");
    print_bits8(x);

    ui32 y = x ^ (x - 1u);

    printf("x ^ (x - 1u) in binary: ");
    print_bits8(y);

    return 0;
}
