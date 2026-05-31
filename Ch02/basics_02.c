#include "../includes/utils.h"

int main() {
    u32 x = 0b10100111;

    printf("x in binary: ");
    println_bits8(x);

    u32 y = x | (x + 1u);

    printf("x | (x + 1u) in binary: ");
    println_bits8(y);

    return 0;
}
