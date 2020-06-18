int singleNumber(int *nums, int numsSize) {
    int s = *nums;
    for (int i = 1; i < numsSize; ++i)
        s ^= nums[i];
    return s;
}
