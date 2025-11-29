#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t i = 0xFFFFFFFF;

    do {
        i = i + 1;
        printf("i = %u\n", i);
    } while (i < 0xFFFFFFFF);

    return 0;
}
