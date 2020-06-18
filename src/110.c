#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int balanced(struct TreeNode *root) {
    if (!root)
        return 0;
    int left = balanced(root->left);
    if (left < 0)
        return -1;
    int right = balanced(root->right);
    if (right < 0)
        return -1;
    if (left - right > 1 || right - left > 1)
        return -1;
    return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode *root) {
    return balanced(root) >= 0;
}
