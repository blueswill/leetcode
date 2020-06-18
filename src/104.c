#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *n) {
    if (!n)
        return 0;
    int d1 = maxDepth(n->left);
    int d2 = maxDepth(n->right);
    return (d1 > d2 ? d1 : d2) + 1;
}
