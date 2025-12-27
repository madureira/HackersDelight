#include "../includes/utils.h"

int main() {
    u32 x = 0b01011000;

    printf("x in binary: ");
    print_bits8(x);

    u32 y = x ^ (x - 1u);

    printf("x ^ (x - 1u) in binary: ");
    print_bits8(y);

    return 0;
}
