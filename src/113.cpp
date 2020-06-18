#include <iostream>
#include <climits>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void merge(vector<vector<int>> &r1, vector<vector<int>> &r2, int val) {
            for (vector<int> &v : r2) {
                v.push_back(val);
                r1.push_back(v);
            }
        }
        bool is_leaf(TreeNode *t) {
            return !t->left && !t->right;
        }
        vector<vector<int>> _pathSum(TreeNode* root, int sum) {
            vector<vector<int>> res;
            if (!root || (is_leaf(root) && root->val != sum))
                return res;
            if (is_leaf(root) && root->val == sum) {
                res.push_back({root->val});
                return res;
            }
            vector<vector<int>> l = _pathSum(root->left, sum - root->val);
            vector<vector<int>> r = _pathSum(root->right, sum - root->val);
            merge(res, l, root->val);
            merge(res, r, root->val);
            return res;
        }
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            auto res = _pathSum(root, sum);
            vector<vector<int>> ret;
            for (vector<int> &r : res)
                ret.push_back(vector<int>(r.rbegin(), r.rend()));
            return ret;
        }
};
