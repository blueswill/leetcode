#include <stdio.h>

int removeDuplicates(int *num, int size) {
    if (!size)
        return 0;
    int ind = 0;
    for (int i = 0; i < size; ++i) {
        if (num[i] != num[ind])
            num[++ind] = num[i];
    }
    return ind + 1;
}

int main(void) {
    int test[] = {1};
    int s = removeDuplicates(test, sizeof(test) / sizeof(int));
    for (int i = 0; i < s; ++i) {
        printf("%d ", test[i]);
    }
    return 0;
}
