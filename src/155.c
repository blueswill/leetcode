#include <stdlib.h>
#include <stdio.h>

#define DEFINE_BUF(type, name) \
    struct name { \
        int _size; \
        int _alloc; \
        type *_pool; \
    }; \
    void name##_init(struct name *_p) { \
        _p->_size = 0; _p->_alloc = 1; \
        _p->_pool = malloc(sizeof(type) * _p->_alloc); \
    } \
    void name##_insert(struct name *_p, type _data) { \
        if (_p->_size == _p->_alloc) { \
            _p->_alloc <<= 1; \
            _p->_pool = realloc(_p->_pool, sizeof(type) * _p->_alloc); \
        } \
        _p->_pool[_p->_size++] = _data; \
    } \
    void name##_free(struct name *_p) { \
        free(_p->_pool); \
    }

#define get_top(b) (&(b)->_pool[(b)->_size - 1])
#define pop(b) (--(b)->_size)
#define isempty(b) (!(b)->_size)

struct Int {
    int val;
    int ref;
};

DEFINE_BUF(struct Int, buf_Int);
DEFINE_BUF(int, buf_int);

typedef struct {
    struct buf_int t;
    struct buf_Int v;
} MinStack;

int minStackTop(MinStack *s) {
    return *get_top(&s->t);
}

int minStackGetMin(MinStack *s) {
    return get_top(&s->v)->val;
}

void minStackPush(MinStack *stack, int val) {
    buf_int_insert(&stack->t, val);
    struct Int n = {val, 1}, *top = get_top(&stack->v);
    if (isempty(&stack->v) || top->val > val)
        buf_Int_insert(&stack->v, n);
    else if (top->val == val)
        ++top->ref;
}

void minStackPop(MinStack *stack) {
    if (isempty(&stack->t))
        return;
    int *t = get_top(&stack->t);
    struct Int *v = get_top(&stack->v);
    if (*t == v->val) {
        --v->ref;
        if (!v->ref)
            pop(&stack->v);
    }
    pop(&stack->t);
}

MinStack *minStackCreate(void) {
    MinStack *ret = malloc(sizeof(MinStack));
    buf_Int_init(&ret->v);
    buf_int_init(&ret->t);
    return ret;
}

void minStackFree(MinStack *s) {
    buf_Int_free(&s->v);
    buf_int_free(&s->t);
    free(s);
}

int main(void) {
    MinStack *s = minStackCreate();
    minStackPush(s, -2);
    minStackPush(s, 0);
    minStackPush(s, -3);
    printf("%d\n", minStackGetMin(s));
    minStackFree(s);
    return 0;
}
