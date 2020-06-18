#include<stdio.h>
#include<limits.h>

#define ABS(n) ((n) > 0 ? (n) : (-(n)))

int reverse(int n) {
    int i = n;
    int r = 0;
    int count = 0;
    while (n) {
        ++count;
        if (count == 10 && (r > (INT_MAX - ABS(n % 10)) / 10))
            return 0;
        r = r * 10 + ABS(n % 10);
        n /= 10;
    }
    if (i < 0)
        return -r;
    return r;
}

int main(int argc, char *argv[])
{
    printf("%d\n", reverse(INT_MIN));
    return 0;
}
