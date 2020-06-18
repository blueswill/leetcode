#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *get_min(struct ListNode **l1, struct ListNode **l2) {
    struct ListNode **min = l1;
    if ((*min)->val > (*l2)->val)
        min = l2;
    struct ListNode *ret = *min;
    *min = (*min)->next;
    return ret;
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode new = {};
    struct ListNode *tail = &new;
    while (l1 && l2) {
        struct ListNode *h = get_min(&l1, &l2);
        tail->next = h;
        tail = h;
    }
    tail->next = (void *)((uintptr_t)l1 | (uintptr_t)l2);
    return new.next;
}

struct ListNode *create_list(int num, ...) {
    struct ListNode new = {};
    struct ListNode *tail = &new;
    va_list ap;
    va_start(ap, num);
    for (int i = 0; i < num; ++i) {
        int val = va_arg(ap, int);
        struct ListNode *n = malloc(sizeof(struct ListNode));
        n->val = val;
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
    va_end(ap);
    return new.next;
}

int main(void) {
    struct ListNode *l1 = create_list(3,1,2,4);
    struct ListNode *l2 = create_list(5,1,3,4,5,6);
    struct ListNode *n = mergeTwoLists(l1, l2);
    while (n) {
        printf("%d ", n->val);
        n = n->next;
    }
    return 0;
}
