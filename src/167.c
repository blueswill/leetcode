#include <stdio.h>
#include <stdlib.h>

int binary_search(int *num, int f, int e, int t){
    if (t == num[f])
        return f;
    if (t == num[e - 1])
        return e - 1;
    while (f < e) {
        int m = (f + e) / 2;
        if (num[m] < t)
            f = m + 1;
        else if (num[m] == t)
            return m;
        else
            e = m;
    }
    return -1;
}

int *twoSum(int *num, int size, int target, int *retsize) {
    int i;
    int *ret = malloc(sizeof(int) * 2);
    *retsize = 2;
    for (i = 0; i < size; ++i) {
        int r = binary_search(num, i + 1, size, target - num[i]);
        if (r > 0) {
            ret[0] = i + 1;
            ret[1] = r + 1;
            return ret;
        }
    }
    *retsize = 0;
    return NULL;
}

int main(void) {
    int test[] = {2,7,9,11};
    int target = 15;
    int retsize;
    int *ret = twoSum(test, sizeof(test) / sizeof(int), target, &retsize);
    if (ret) {
        printf("%d %d\n", ret[0], ret[1]);
    }
    free(ret);
    return 0;
}
