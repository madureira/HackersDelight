#include "../includes/utils.h"

/**
 * Checks if x is a power of 2
 * @returns 1 if x is a power of 2, 0 otherwise
 */
int is_power_of_two(ui32 x) {
    // x != 0 ensures we do not count 0 as a power of 2
    return x != 0 && ((x & (x - 1)) == 0);
}

int main() {
    ui32 x = 0b01011000; // 01011000 in binary

    printf("x in binary: ");
    print_bits8(x);

    ui32 y = x & (x - 1u); // 01010000

    printf("x & (x - 1u) in binary: ");
    print_bits8(y);

    printf("\nChecking powers of two:\n");

    ui32 values[] = {0, 1, 2, 3, 4, 5, 8, 16, 18, 32};
    i32 n = sizeof(values) / sizeof(values[0]);

    for (i32 i = 0; i < n; i++) {
        ui32 x = values[i];

        if (is_power_of_two(x)) {
            printf("%u is a power of 2\n", x);
        } else {
            printf("%u is not a power of 2\n", x);
        }
    }

    return 0;
}
