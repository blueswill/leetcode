#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int countPrimes(int n) {
    if (n <= 2)
        return 0;
    uint8_t *isNotPrime = calloc(n + 1, 1);
    int c = 0, i;
    for (i = 2; i <= n / i; ++i) {
        if (!isNotPrime[i]) {
            ++c;
            for (int j = i; j <= n / i; ++j)
                isNotPrime[j * i] = 1;
        }
    }
    for (; i < n; ++i)
        c += !isNotPrime[i];
    free(isNotPrime);
    return c;
}

int main(int argc, char *argv[])
{
    printf("%d\n", countPrimes(strtol(argv[1], NULL, 10)));
    return 0;
}
