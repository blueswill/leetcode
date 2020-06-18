#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

#define NEW(type) malloc(sizeof(type))

struct TreeNode *sortedArrayToBST(int *nums, int size) {
    if (!size)
        return NULL;
    struct TreeNode *r = NEW(struct TreeNode);
    int mid = size / 2;
    r->val = nums[mid];
    r->left = sortedArrayToBST(nums, mid);
    r->right = sortedArrayToBST(nums + mid + 1, size - mid - 1);
    return r;
}
