#include <stdio.h>
#include <stdlib.h>

int output(char *buf, int count, char c) {
    int n = sprintf(buf, "%d", count);
    buf[n] = c;
    return n + 1;
}

char *countAndSay(int n) {
    char *buf = malloc(10000);
    char *tmp = malloc(10000);
    int size = 1;
    buf[0] = '1';
    buf[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        int ind = 0;
        int prev = 0;
        for (int j = 1; j <= size; ++j) {
            if (buf[j] != buf[j - 1]) {
                ind += output(tmp + ind, j - prev, buf[j - 1]);
                prev = j;
            }
        }
        tmp[ind] = 0;
        char *t = tmp;
        tmp = buf;
        buf = t;
        size = ind;
    }
    return buf;
}

int main(int argc, char **argv) {
    printf("%s\n", countAndSay(strtol(argv[1], NULL, 10)));
    return 0;
}
