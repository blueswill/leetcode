class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void connect_two_tree(Node *left, Node *right) {
        Node *left_down = left, *right_down = right;
        while (left_down) {
            left_down->next = right_down;
            if (left_down->right)
                left_down = left_down->right;
            else
                left_down = left_down->left;
            if (right_down->left)
                right_down = right_down->left;
            else
                right_down = right_down->right;
        }
    }
    Node *_connect(Node *sub) {
        if (!sub)
            return sub;
        if (sub->left)
            _connect(sub->left);
        if (sub->right)
            _connect(sub->right);
        if (sub->left && sub->right)
            connect_two_tree(sub->left, sub->right);
        return sub;
    }
    Node* connect(Node* root) {
        _connect(root);
        Node *right = root;
        while (right) {
            right->next = nullptr;
            if (right->right)
                right = right->right;
            else
                right = right->left;
        }
        return root;
    }
};
