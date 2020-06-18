#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *addBinary(const char *a, const char *b) {
    size_t s1 = strlen(a), s2 = strlen(b);
    if (s2 > s1) {
        const char *t = b;
        b = a;
        a = t;
        size_t u = s1;
        s1 = s2;
        s2 = u;
    }
    size_t max = s1 + 2;
    size_t ind = s1;
    char *r = malloc(max);
    r[ind] = '\0';
    int c = 0;
    while (s2) {
        int s = a[s1 - 1] + b[s2 - 1] - 2 * '0' + c;
        r[--ind] = s % 2 + '0';
        c = s / 2;
        --s1, --s2;
    }
    while (s1) {
        int s = a[s1 - 1] - '0' + c;
        r[--ind] = s % 2 + '0';
        c = s / 2;
        --s1;
    }
    if (c) {
        memmove(r + 1, r, max - 1);
        r[0] = '1';
    }
    return r;
}

int main(int argc, char *argv[]) {
    printf("%s\n", addBinary(argv[1], argv[2]));
    return 0;
}
