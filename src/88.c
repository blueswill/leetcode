#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *tmp = malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, k = 0;
    while (i < m || j < n) {
        if (i < m && j < n) {
            if (nums1[i] < nums2[j])
                tmp[k++] = nums1[i++];
            else
                tmp[k++] = nums2[j++];
        }
        else if (i < m)
            tmp[k++] = nums1[i++];
        else
            tmp[k++] = nums2[j++];
    }
    memmove(nums1, tmp, sizeof(int) * (m + n));
}
