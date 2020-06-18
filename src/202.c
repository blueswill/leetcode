#include <stdlib.h>
#include <stdbool.h>

int map(int n) {
    int r = 0;
    while (n) {
        int s = n % 10;
        n /= 10;
        r += s * s;
    }
    return r;
}

bool isHappy(int n) {
    bool checked[1000] = {};
    while (n != 1) {
        n = map(n);
        if (checked[n])
            return false;
        checked[n] = true;
    }
    return true;
}
