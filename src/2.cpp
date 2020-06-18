struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    private:
        ListNode *add(ListNode *l1, ListNode *l2, int c) {
            if (!l1 && !l2) {
                if (c)
                    return new ListNode(c);
                return nullptr;
            }
            int left = (l1 ? l1->val : 0);
            int right = (l2 ? l2->val : 0);
            ListNode *ln = (l1 ? l1->next : l1);
            ListNode *rn = (l2 ? l2->next : l2);
            ListNode *tail = add(ln, rn, (left + right + c) / 10);
            ListNode *n = new ListNode((left + right + c) % 10);
            n->next = tail;
            return n;
        }
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            auto ptr = add(l1, l2, 0);
            if (!ptr)
                return new ListNode(0);
            return ptr;
        }
};
