#include <stdint.h>

int hammingWeight(uint32_t n) {
   const int  tab[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
   int r = 0;
   for (int i = 0; i < 32; i += 4)
       r += tab[(n >> i) & 0xf];
   return r;
}
