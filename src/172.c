#include <stdio.h>
#include <stdlib.h>

int trailingZeroes(int n) {
    int r = 0;
    int i;
    for (i = 5; i <= n / 5; i *= 5) {
        r += n / i;
    }
    if (i <= n)
        r += n / i;
    return r;
}

int main(int argc, char *argv[])
{
    printf("%d\n", trailingZeroes(strtol(argv[1], NULL, 10)));
    return 0;
}
