#include <stdlib.h>

int *getRow(int row, int *size) {
    *size = row + 1;
    int *b = malloc(sizeof(int) * *size);
    b[0] = 1;
    for (int i = 1; i < *size; ++i)
        b[i] = b[i - 1] / i + ((b[i - 1] % i) * (row - i + 1)) / i;
    return b;
}
