#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    const uint32_t _tb[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    uint32_t a = (n & 0xf), b = ((n >> 4) & 0xf), c = ((n >> 8) & 0xf), d = ((n >> 12) & 0xf),
             e = ((n >> 16) & 0xf), f = ((n >> 20) & 0xf), g = ((n >> 24) & 0xf), h = ((n >> 28) & 0xf);
    return (_tb[a] << 28) | (_tb[b] << 24) | (_tb[c] << 20) | (_tb[d] << 16) |
        (_tb[e] << 12) | (_tb[f] << 8) | (_tb[g] << 4) | _tb[h];
}
