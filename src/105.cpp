#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        unsigned position(vector<int>& v, unsigned s, unsigned e, int m) {
            unsigned i = 0;
            for (i = s; i <= e; ++i) {
                if (v[i] == m)
                    return i;
            }
            return -1;
        }
        TreeNode *_buildTree(vector<int>& preorder, unsigned ps, unsigned pe,
                            vector<int>&inorder, unsigned is, unsigned ie) {
            if (ps > pe)
                return NULL;
            TreeNode *node = new TreeNode(preorder[ps]);
            if (ps == pe)
                return node;
            unsigned p = position(inorder, is, ie, node->val);
            node->left = _buildTree(preorder, ps + 1, ps + (p - is), inorder, is, p - 1);
            node->right = _buildTree(preorder, ps + (p - is) + 1, pe, inorder, p + 1, ie);
            return node;
        }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.size() == 0)
                return NULL;
            return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        }
};

int main(void) {
    Solution s;
    std::vector<int> p{3,9,20,15,7}, i{9,3,15,20,7};
    TreeNode *node = s.buildTree(p, i);
    return 0;
}
