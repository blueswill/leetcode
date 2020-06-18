#include <stdio.h>

int removeElement(int *nums, int size, int val) {
    int ind = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] != val)
            nums[ind++] = nums[i];
    }
    return ind;
}

int main(void) {
    int a[] = {3,2,2,3};
    int s = removeElement(a, sizeof(a) / sizeof(int), 3);
    int i;
    for (i = 0; i < s; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
