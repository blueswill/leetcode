#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    if (!numRows) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int **ret = malloc(sizeof(int *) * numRows);
    int *sret = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i) {
        int *b = malloc(sizeof(int) * (i + 1));
        int **prev = ret + i - 1;
        b[0] = 1;
        for (int j = 1; j < i; ++j)
            b[j] = prev[0][j - 1] + prev[0][j];
        b[i] = 1;
        ret[i] = b;
        sret[i] = i + 1;
    }
    *returnSize = numRows;
    *returnColumnSizes = sret;
    return ret;
}
