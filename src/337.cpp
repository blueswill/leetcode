#include <unordered_map>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        unordered_map<TreeNode *, int[2]> table;
        int _rob(TreeNode *root, int root_can_rob) {
            if (!root)
                return 0;
            auto f = table.find(root);
            if (f != table.end())
                return f->second[root_can_rob];
            int tt = root->val + _rob(root->left, 0) + _rob(root->right, 0);
            int tf = _rob(root->left, 1) + _rob(root->right, 1);
            table[root][1] = max(tt, tf);
            table[root][0] = tf;
            if (root_can_rob)
                return table[root][1];
            return table[root][0];
        }
        int rob(TreeNode* root) {
            return _rob(root, true);
        }
};
