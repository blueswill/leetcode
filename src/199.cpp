#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int deep;
    public:
        vector<int> dfs(TreeNode *root, int depth) {
            vector<int> r;
            if (!root)
                return r;
            if (depth > deep) {
                r.push_back(root->val);
                ++deep;
            }
            auto right = dfs(root->right, depth + 1);
            auto left = dfs(root->left, depth + 1);
            r.reserve(right.size() + left.size() + r.size());
            r.insert(r.end(), right.begin(), right.end());
            r.insert(r.end(), left.begin(), left.end());
            return r;
        }
        vector<int> rightSideView(TreeNode *root) {
            deep = -1;
            return dfs(root, 0);
        }
};
