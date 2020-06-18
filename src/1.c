#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int *nums, int *s, int begin, int end, int target) {
    int e = end - 1;
    if (target <= nums[s[begin]])
        return begin;
    if (target > nums[s[e]])
        return -1;
    while (begin < e) {
        int mid = (begin + e) / 2;
        if (nums[s[mid]] >= target)
            e = mid;
        else
            begin = mid + 1;
    }
    if (begin >= end)
        return -1;
    return begin;
}

int int_comp(const void *a, const void *b, void *nums) {
    return ((int *)nums)[*(int *)a] - ((int *)nums)[*(int *)b];
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    if (returnSize)
        *returnSize = 2;
    int *r = malloc(sizeof(int) * 2);
    int *s = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
        s[i] = i;
    qsort_r(s, numsSize, sizeof(int), int_comp, nums);
    for (int i = 0; i < numsSize; ++i) {
        int t = target - nums[s[i]];
        int u = search(nums, s, i + 1, numsSize, t);
        if (u >= 0 && t == nums[s[u]]) {
            r[0] = s[i];
            r[1] = s[u];
            free(s);
            return r;
        }
    }
    free(s);
    free(r);
    return NULL;
}

int main(void) {
    int nums[] = {7,2,15,11};
    int *r = twoSum(nums, 4, 9, NULL);
    if (r)
        printf("%d %d\n", r[0], r[1]);
}
