#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            if (!root)
                return {};
            string val = to_string(root->val);
            string valt = val + "->";
            vector<string> l = binaryTreePaths(root->left),
                r = binaryTreePaths(root->right);
            vector<string> res;
            res.reserve(l.size() + r.size() + 1);
            for (string s : l)
                res.push_back(valt + s);
            for (string s : r)
                res.push_back(valt + s);
            if (res.empty())
                res.push_back(val);
            return res;
        }
};
