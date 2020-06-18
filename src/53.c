#include <stdio.h>
#include <limits.h>

int maxSubArray(int *nums, int size) {
    int max = nums[0];
    int sum = nums[0];
    for (int i = 1; i < size; ++i) {
        if (sum + nums[i] > nums[i])
            sum += nums[i];
        else
            sum = nums[i];
        if (sum > max)
            max = sum;
    }
    return max;
}

int main(void) {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(a, sizeof(a) / sizeof(int)));
    return 0;
}
