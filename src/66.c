#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *plusOne(int *num, int size, int *retsize) {
    int *new = malloc(sizeof(int) * (size + 1));
    int c = 1, i;
    for (i = size - 1; i >= 0; --i) {
        new[i] = num[i] + c;
        c = new[i] / 10;
        new[i] %= 10;
    }
    *retsize = size;
    if (c != 0) {
        memmove(new + 1, new, sizeof(int) * size);
        new[0] = c;
        ++*retsize;
    }
    return new;
}

int main(void) {
    int a[] = {9};
    int size, i;
    int *ret = plusOne(a, sizeof(a) / sizeof(int), &size);
    for (i = 0; i < size; ++i) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}
