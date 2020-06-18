#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode new = {};
    struct ListNode *tail = &new;
    while (head) {
        tail->next = head;
        tail = head;
        tail->next = NULL;
        head = head->next;
        while (head && head->val == tail->val)
            head = head->next;
    }
    return new.next;
}

int main(void) {
    struct ListNode l1={3, NULL};
    struct ListNode l2={3, NULL};
    struct ListNode l3={2, NULL};
    struct ListNode l4={1, NULL};
    struct ListNode l5={1, NULL};
    l5.next = &l4;
    l4.next = &l3;
    l3.next = &l2;
    l2.next = &l1;
    struct ListNode *r = deleteDuplicates(&l5);
    while (r) {
        printf("%d ", r->val);
        r = r->next;
    }
    return 0;
}
