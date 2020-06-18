#include <stdio.h>
#include <stdlib.h>

static int t[256] = {
['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50, ['C'] = 100, ['D'] = 500, ['M'] = 1000
};

int next_token(char **s) {
    int n = (*s)[1], u = **s;
    if ((u == 'I' && (n == 'V' || n == 'X')) ||
            (u == 'X' && (n == 'L' || n == 'C')) ||
            (u == 'C' && (n == 'D' || n == 'M'))) {
        *s += 2;
        return t[n] - t[u];
    }
    ++*s;
    return t[u];
}

int romanToInt(char *s) {
    int r = 0;
    char *p = s;
    while (*p) {
        int n = next_token(&p);
        r += n;
    }
    return r;
}

int main(int argc, char *argv[])
{
    printf("%d\n", romanToInt(argv[1]));
    return 0;
}
