#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x) {
    long u = x + 1, u0 = x + 2;
    while (u < u0 && u) {
        u0 = u;
        u = (u + x / u) / 2;
    }
    if (u * u <= x)
        return u;
    return u - 1;
}

int main(int argc, char *argv[]) {
    printf("%d\n", mySqrt(strtol(argv[1], NULL, 10)));
    return 0;
}
