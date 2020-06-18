#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

bool is_equal(struct TreeNode *p, struct TreeNode *q) {
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return p->val == q->val && is_equal(p->left, q->right) && is_equal(p->right, q->left);
}

bool isSymmetric(struct TreeNode *node) {
    if (!node)
        return true;
    return is_equal(node->left, node->right);
}
