struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        int sum_with_prefix(TreeNode *root, int prefix) {
            int res = 0;
            prefix = prefix * 10 + root->val;
            if (!root->left && !root->right)
                return prefix;
            if (root->left)
                res += sum_with_prefix(root->left, prefix);
            if (root->right)
                res += sum_with_prefix(root->right, prefix);
            return res;
        }
        int sumNumbers(TreeNode* root) {
            if (!root)
                return 0;
            return sum_with_prefix(root, 0);
        }
};
