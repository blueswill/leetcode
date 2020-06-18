#include <stdio.h>

int titleToNumber(const char *s) {
    const char *ptr = s;
    int n = 0;
    while (*ptr)
        n = n * 26 + (*ptr++ - 'A' + 1);
    return n;
}

int main(int argc, char *argv[])
{
    printf("%d\n", titleToNumber(argv[1]));
    return 0;
}
