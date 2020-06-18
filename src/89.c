#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int *grayCode(int n, int *returnSize){
    int size = (1 << n);
    int *result = malloc(sizeof(int) * size);
    int offset = 0;
    if (returnSize)
        *returnSize = size;
    result[offset++] = 0;
    for (int i = 0; i < n; ++i) {
        int t = (1 << i);
        for (int j = offset - 1; j >= 0; --j)
            result[offset++] = result[j] ^ t;
    }
    return result;
}

int main(int argc, char **argv) {
    int *result, size;
    int l = strtol(argv[1], NULL, 10);
    result = grayCode(l, &size);
    for (int i = 0; i < size; ++i)
        printf("%d ", result[i]);
    putchar('\n');
    return 0;
}
