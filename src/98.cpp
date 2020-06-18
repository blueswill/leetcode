#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        bool _isValidBST(TreeNode *root, long minQ, long maxQ) {
            bool ret = true;
            if (!root) return true;
            if (root->val < minQ || root->val > maxQ)
                return false;
            return _isValidBST(root->left, minQ, (long)root->val - 1) &&
                _isValidBST(root->right, (long)root->val + 1, maxQ);
        }
    public:
        bool isValidBST(TreeNode *root) {
            return _isValidBST(root, INT_MIN, INT_MAX);
        }
};
