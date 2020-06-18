#include <map>
#include <utility>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        pair<int, int> start_from(TreeNode *sub) {
            if (!sub) return {0, INT_MIN};
            pair<int, int> left = start_from(sub->left);
            pair<int, int> right = start_from(sub->right);
            pair<int, int> result = {sub->val, sub->val};
            result.first = std::max(result.first, result.first + std::max(left.first, right.first));
            if (left.first > 0)
                result.second += left.first;
            if (right.first > 0)
                result.second += right.first;
            result.second = std::max(left.second, std::max(right.second, result.second));
            return result;
        }
        int maxPathSum(TreeNode* root) {
            pair<int, int> result = start_from(root);
            return result.second;
        }
};
