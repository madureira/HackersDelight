#include <stdio.h>
#include <stdint.h>

void print_bits8(uint32_t x) {
    int32_t total_bits = 8;
    for (int32_t i = total_bits - 1; i >= 0; i--) {
        uint32_t mask = 1u << i;
        putchar((x & mask) ? '1' : '0');
    }
    printf("\n");
}

int main() {
    uint32_t x = 0b10100111;

    printf("x in binary: ");
    print_bits8(x);

    uint32_t y = x & (x + 1);

    printf("x & (x + 1) in binary: ");
    print_bits8(y);

    return 0;
}
