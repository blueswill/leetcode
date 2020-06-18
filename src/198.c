#include <stdlib.h>

#define Y 1
#define N 0

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int *nums, int numsSize) {
    int (*t)[2];
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    t = malloc(sizeof(*t) * numsSize);
    t[0][Y] = nums[0];
    t[0][N] = 0;
    t[1][Y] = nums[1];
    t[1][N] = t[0][Y];
    for (int i = 2; i < numsSize; ++i) {
        t[i][Y] = MAX(t[i - 2][Y], t[i - 2][N]) + nums[i];
        t[i][N] = MAX(t[i - 1][Y], t[i - 1][N]);
    }
    int ret = MAX(t[numsSize - 1][Y], t[numsSize - 1][N]);
    free(t);
    return ret;
}
