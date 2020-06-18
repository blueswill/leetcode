#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    int a = 1, b = 1, c = 2;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
