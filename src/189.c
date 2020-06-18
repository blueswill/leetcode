void swap(int *num, int a, int b) {
    while (a < b) {
        int s = num[a];
        num[a] = num[b];
        num[b] = s;
        ++a;
        --b;
    }
}

void rotate(int *nums, int numsSize, int k) {
    k %= numsSize;
    swap(nums, 0, numsSize - 1);
    swap(nums, 0, k);
    swap(nums, k + 1, numsSize - 1);
}
