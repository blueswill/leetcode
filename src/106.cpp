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
            for (i = s; i < e; ++i) {
                if (v[i] == m)
                    return i;
            }
            return -1;
        }
        TreeNode *_buildTree(vector<int>& inorder, unsigned ps, unsigned pe,
                            vector<int>&postorder, unsigned is, unsigned ie) {
            if (ps >= pe)
                return NULL;
            TreeNode *node = new TreeNode(postorder[ie - 1]);
            if (ps == pe - 1)
                return node;
            unsigned p = position(inorder, ps, pe, node->val);
            unsigned len = p - ps;
            node->left = _buildTree(inorder, ps, p, postorder, is, is + len);
            node->right = _buildTree(inorder, p + 1, pe, postorder, is + len, ie - 1);
            return node;
        }
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return _buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        }
};

int main(void) {
    Solution s;
    std::vector<int> p{9,15,7,20,3}, i{9,3,15,20,7};
    TreeNode *node = s.buildTree(i, p);
    return 0;
}
