#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct buf {
    char *str;
    size_t size;
    size_t cur;
};

struct buf *buf_init(void) {
    struct buf *b = malloc(sizeof(struct buf));
    b->str = malloc(1024);
    b->size = 1024;
    b->cur = 0;
    return b;
}

void buf_destroy(struct buf *b) {
    free(b);
}

void write_str(struct buf *b, const char *str, int start, int end, int repeat) {
    int s = (end - start) * repeat;
    if (!s)
        return;
    if (b->cur + s >=  b->size) {
        size_t new = s + (b->size << 1);
        int f = (str == b->str);
        b->str = realloc(b->str, new);
        if (f)
            str = b->str;
        b->size = new;
    }
    for (int i = 0; i < repeat; ++i, b->cur += end - start)
        memmove(b->str + b->cur, str + start, end - start);
}

int parse_1b(struct buf *b, const char *s, int start);

int parse_b(struct buf *b, const char *s, int start) {
    int i;
    for (i = start; s[i] != ']' && s[i]; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            write_str(b, s, start, i, 1);
            i = start = parse_1b(b, s, i);
            --i;
        }
    }
    write_str(b, s, start, i, 1);
    return i;
}

int parse_1b(struct buf *b, const char *s, int start) {
    int r = 0, i;
    for (i = start; s[i] >= '0' && s[i] <= '9'; ++i)
        r = r * 10 + s[i] - '0';
    ++i; /* ignore [  */
    int tag1 = b->cur;
    int now = parse_b(b, s, i);
    assert(s[now] == ']');
    int tag2 = b->cur;
    write_str(b, b->str, tag1, tag2, r - 1);
    return now + 1;
}

char *decodeString(const char *s) {
    struct buf *b = buf_init();
    int now = parse_b(b, s, 0);
    assert(!s[now]);
    write_str(b, "", 0, 1, 1);
    char *r = b->str;
    buf_destroy(b);
    return r;
}

int main(int argc, char **argv) {
    char *str = decodeString(argv[1]);
    printf("%s\n", str);
    free(str);
    return 0;
}
