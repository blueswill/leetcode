#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

#define IS_LEAF(n) (!(n)->left && !(n)->right)

bool hasPathSum(struct TreeNode *root, int sum) {
    if (!root)
        return false;
    if (IS_LEAF(root) && root->val == sum)
        return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
