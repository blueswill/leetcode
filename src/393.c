#include<stdbool.h>
#include<stdio.h>

#define shl(n) ({ __asm__("shl $1, %0" : "+r"(n)); n; })

int next(int *data, int s) {
    signed char p = (signed char)data[s];
    if (p >= 0) return 1;
    if (shl(p) >= 0) return -1;
    if (shl(p) >= 0) return 2;
    if (shl(p) >= 0) return 3;
    if (shl(p) >= 0) return 4;
    return -1;
}

bool validUtf8(int *data, int t) {
    if (t < 0)
        return false;
    for (int i = 0; i < t; ++i) {
        int s = next(data, i);
        if (s < 0)
            return false;
        for (int j = 1; j < s; ++j)
            if (i >= t - 1 || (data[++i] & 0xc0) != 0x80)
                return false;
    }
    return true;
}
