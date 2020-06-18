#include<stdio.h>
#include<stdlib.h>

char *licenseKeyFormatting(const char *s, int K) {
    int an = 0, i;
    for (i = 0; s[i]; ++i)
        if (s[i] != '-')
            ++an;
    if (!an) {
        char *r = malloc(1);
        *r = 0;
        return r;
    }
    int b = (an + K - 1) / K - 1;
    int p = b + an;
    char *r = malloc(p + 1);
    r[p] = '\0';
    int q = 0;
    while (--i >= 0) {
        if (s[i] == '-')
            continue;
        if (s[i] >= 'a' && s[i] <= 'z')
            r[--p] = s[i] - 'a' + 'A';
        else
            r[--p] = s[i];
        ++q;
        if (q % K == 0 && p)
            r[--p] = '-';
    }
    return r;
}

int main(void) {
    const char *test = "1";
    printf("%s\n", licenseKeyFormatting(test, 3));
    return 0;
}
