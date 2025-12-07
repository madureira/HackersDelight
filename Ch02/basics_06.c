#include "../includes/utils.h"

int main() {
    uint32 x = 0b10101000;

    printf("x in binary: ");
    print_bits8(x);

    uint32 y = ~x | (x - 1);

    printf("~x | (x - 1) in binary: ");
    print_bits8(y);

    return 0;
}
