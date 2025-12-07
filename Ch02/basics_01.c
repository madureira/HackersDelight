#include <stdio.h>
#include <stdint.h>

void print_bits8(uint32_t x) {
    int total_bits = 8;
    for (int i = total_bits - 1; i >= 0; i--) {
        uint32_t mask = 1u << i;
        putchar((x & mask) ? '1' : '0');
    }
    printf("\n");
}

int is_power_of_two(unsigned int x) {
    // x != 0 ensures we do not count 0 as a power of 2
    return x != 0 && ((x & (x - 1)) == 0);
}

int main() {
    uint32_t x = 0b01011000; // 01011000 in binary

    printf("x in binary: ");
    print_bits8(x);

    uint32_t y = x & (x - 1); // 01010000

    printf("x & (x - 1) in binary: ");
    print_bits8(y);

    printf("\nChecking powers of two:\n");

    uint32_t values[] = {0, 1, 2, 3, 4, 5, 8, 16, 18, 32};
    int32_t n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        uint32_t x = values[i];

        if (is_power_of_two(x)) {
            printf("%u is a power of 2\n", x);
        } else {
            printf("%u is not a power of 2\n", x);
        }
    }

    return 0;
}
