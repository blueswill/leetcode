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
        Node *get_next(Node **parent_ptr, Node *cur) {
            Node *parent = *parent_ptr;
            while (parent) {
                if (parent->left && parent->left != cur) {
                    *parent_ptr = parent;
                    return parent->left;
                }
                if (parent->right && parent->right != cur) {
                    *parent_ptr = parent->next;
                    return parent->right;
                }
                parent = parent->next;
            }
            return nullptr;
        }
        void connect_layer(Node *cur, Node *parent) {
            while (cur) {
                Node *next = get_next(&parent, cur);
                cur->next = next;
                cur = next;
            }
        }
        Node* connect(Node* root) {
            Node *cur = root;
            Node *parent = nullptr;
            while (true) {
                connect_layer(cur, parent);
                while (cur && !cur->left && !cur->right)
                    cur = cur->next;
                if (!cur)
                    break;
                if (cur->left) {
                    parent = cur;
                    cur = cur->left;
                }
                else {
                    parent = cur->next;
                    cur = cur->right;
                }
            }
            return root;
        }
};
