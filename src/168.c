#include <stdio.h>
#include <stdlib.h>

char *convertToTitle(int n) {
    char *buf = malloc(50);
    char *ptr = buf;
    while (n) {
        *ptr++ = (n % 26 + 25) % 26 + 'A';
        n = (n - 1) / 26;
    }
    *ptr = '\0';
    char *u = buf;
    while (ptr > u) {
        char t = *--ptr;
        *ptr = *u;
        *u++ = t;
    }
    return buf;
}

int main(int argc, char **argv) {
    printf("%s\n", convertToTitle(strtol(argv[1], NULL, 10)));
    return 0;
}
