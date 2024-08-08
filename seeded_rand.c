#include <stdlib.h>
#include "quantum.h"

uint8_t seeded_rand(uint8_t sides, uint16_t seed) {
    srand(seed);
    return 1 + rand() / ((RAND_MAX + 1u) / sides);
}

void print_roll(uint8_t sides, uint16_t seed) {
    char str[4];
    SEND_STRING("1d");
    sprintf(str, "%d", sides);
    SEND_STRING(str);
    SEND_STRING(": ");
    sprintf(str, "%d", seeded_rand(sides, seed));
    SEND_STRING(str);
}
