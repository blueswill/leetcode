struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        TreeNode *app(TreeNode *root, TreeNode *tail) {
            if (!root) {
                tail->right = nullptr;
                return tail;
            }
            tail->right = root;
            TreeNode *left = root->left, *right = root->right;
            root->left = nullptr;
            tail = app(left, root);
            return app(right, tail);
        }
        void flatten(TreeNode* root) {
            TreeNode tmp(0);
            app(root, &tmp);
        }
};
