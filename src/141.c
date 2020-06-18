#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *n) {
    if (!n)
        return false;
    struct ListNode *n1 = n;
    struct ListNode *n2 = n->next;
    while (n1 && n2) {
        if (n1 == n2 || n1 == n2->next)
            return true;
        n1 = n1->next;
        n2 = n2->next;
        if (n2)
            n2 = n2->next;
    }
    return false;
}
