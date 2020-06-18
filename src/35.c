#include <stdio.h>

/* [i, j) */
int search(int *num, int i, int j, int target) {
    if (num[i] >= target)
        return i;
    if (num[j - 1] < target)
        return j;
    while (i < j) {
        int m = (i + j) / 2;
        if (num[m] >= target)
            j = m;
        else if (num[m] < target)
            i = m + 1;
    }
    return i;
}

int searchInsert(int *nums, int size, int target) {
    if (size == 0)
        return 0;
    return search(nums, 0, size, target);
}

int main(void) {
    int a[] = {1,3,5,6};
    int target = 2;
    printf("%d\n", searchInsert(a, sizeof(a) / sizeof(int), target));
    return 0;
}
