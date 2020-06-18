#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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

DEFINE_BUF(int *, buf_ip);
DEFINE_BUF(int, buf_i);
DEFINE_BUF(struct TreeNode *, buf_t);

int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    struct buf_ip ret;
    struct buf_i size_ret;
    struct buf_t queue;
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    buf_ip_init(&ret);
    buf_i_init(&size_ret);
    buf_t_init(&queue);
    buf_t_insert(&queue, root);
    while (queue._size) {
        struct buf_t new_q;
        int *new = malloc(sizeof(int) * queue._size);
        buf_t_init(&new_q);
        for (int i = 0; i < queue._size; ++i) {
            struct TreeNode *n = queue._pool[i];
            new[i] = n->val;
            if (n->left)
                buf_t_insert(&new_q, n->left);
            if (n->right)
                buf_t_insert(&new_q, n->right);
        }
        buf_ip_insert(&ret, new);
        buf_i_insert(&size_ret, queue._size);
        buf_t_free(&queue);
        queue = new_q;
    }
    buf_t_free(&queue);
    for (int i = 0; i < ret._size / 2; ++i) {
        int *tmp = ret._pool[i];
        int u = size_ret._pool[i];
        ret._pool[i] = ret._pool[ret._size - i - 1];
        ret._pool[ret._size - i - 1] = tmp;
        size_ret._pool[i] = size_ret._pool[ret._size - i - 1];
        size_ret._pool[ret._size - i - 1] = u;
    }
    *returnSize = ret._size;
    *returnColumnSizes = size_ret._pool;
    return ret._pool;
}
