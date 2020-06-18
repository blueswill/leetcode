#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

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

DEFINE_BUF(struct TreeNode *, buf_t);

#define IS_LEAF(n) (!(n)->left && !(n)->right)

int minDepth(struct TreeNode *root) {
    struct buf_t q;
    if (!root)
        return 0;
    if (IS_LEAF(root))
        return 1;
    buf_t_init(&q);
    buf_t_insert(&q, root);
    int ret = 1;
    while (q._size) {
        struct buf_t n;
        buf_t_init(&n);
        for (int i = 0; i < q._size; ++i) {
            struct TreeNode *p = q._pool[i];
            if ((p->left && IS_LEAF(p->left)) ||
                (p->right && IS_LEAF(p->right))) {
                buf_t_free(&n);
                buf_t_free(&q);
                return ret + 1;
            }
            if (p->left)
                buf_t_insert(&n, p->left);
            if (p->right)
                buf_t_insert(&n, p->right);
        }
        buf_t_free(&q);
        q = n;
        ++ret;
    }
    buf_t_free(&q);
    return ret + 1;
}
