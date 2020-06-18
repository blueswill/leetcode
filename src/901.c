#include<stdio.h>
#include<stdlib.h>

typedef struct {
    unsigned data[10001];
    unsigned d[10001];
    int index;
} StockSpanner;

StockSpanner *stockSpannerCreate() {
    StockSpanner *r = malloc(sizeof(StockSpanner));
    r->index = 0;
    return r;
}

int StockSpannerNext(StockSpanner *r, int p) {
    int j = r->index;
    int s = 1;
    for (int i = j - 1; i >= 0 && r->data[i] <= p; i -= r->d[i])
        s += r->d[i];
    r->d[j] = s;
    r->data[j] = p;
    ++r->index;
    return s;
}

void stockSpannerFree(StockSpanner *r) {
    free(r);
}

int main(void) {
    StockSpanner *s = stockSpannerCreate();
    unsigned test[] = {100, 80, 60, 70, 60, 75, 85};
    for (int i = 0; i < 7; ++i) {
        printf("%d\n", StockSpannerNext(s, test[i]));
    }
}
