#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct gen_stat {
    char **target;
    int size;
    int offset;
    char *buf;
    int bufsize;
    int i;              //position wait
    int left_n;         //unmatched '('
    int limit;          //unprinted '('
};

void output(struct gen_stat *st) {
    if (st->offset >= st->size) {
        st->target = realloc(st->target, (st->size << 1) * sizeof(*st->target));
        st->size <<= 1;
    }
    char *buf = malloc(st->bufsize);
    memmove(buf, st->buf, st->bufsize);
    st->target[st->offset++] = buf;
}

void gen(struct gen_stat *stat) {
    if (!stat->limit && !stat->left_n) {
        output(stat);
        return;
    }
    if (stat->limit > 0) {
        stat->buf[stat->i++] = '(';
        ++stat->left_n;
        --stat->limit;
        gen(stat);
        --stat->i;
        --stat->left_n;
        ++stat->limit;
    }
    if (stat->left_n > 0) {
        stat->buf[stat->i++] = ')';
        --stat->left_n;
        gen(stat);
        --stat->i;
        ++stat->left_n;
    }
}

char **generateParenthesis(int n, int *returnSize) {
    struct gen_stat stat = {};
    stat.bufsize = n * 2 + 1;
    stat.buf = calloc(stat.bufsize, 1);
    stat.limit = n;
    stat.target = malloc(sizeof(*stat.target) * 1024);
    stat.size = 1024;
    gen(&stat);
    free(stat.buf);
    if (returnSize)
        *returnSize = stat.offset;
    stat.target = realloc(stat.target, stat.offset * sizeof(*stat.target));
    return stat.target;
}

int main(void) {
    int size;
    char **result = generateParenthesis(3, &size);
    for (int i = 0; i < size; ++i) {
        printf("%s\n", result[i]);
    }
    return 0;
}
