#include <vector>
#include <cstring>

using namespace std;

class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }

        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }

        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    private:
        Node *visited[100];
    public:
        Node *copy_current(Node *cur) {
            Node *n = new Node(cur->val, cur->neighbors);
            unsigned i;
            visited[n->val] = n;
            for (i = 0; i < n->neighbors.size(); ++i) {
                if (visited[n->neighbors[i].val])
                    n->neighbors[i] = visited[n->neighbors[i].val];
                else
                    n->neighbors[i] = copy_current(n->neighbors[i]);
            }
            return n;
        }
        Node* cloneGraph(Node* node) {
            memset(visited, 0, sizeof(Node *) * 100);
            if (!node)
                return nullptr;
            return copy_current(node);
        }
};
