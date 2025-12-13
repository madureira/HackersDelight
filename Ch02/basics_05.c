#include "../includes/utils.h"

int main() {
    ui32 x = 0b10100111;

    printf("x in binary: ");
    print_bits8(x);

    ui32 y = ~x & (x + 1);

    printf("~x & (x + 1) in binary: ");
    print_bits8(y);

    return 0;
}
