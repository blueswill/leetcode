#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int n) {
    if (n < 0)
        return false;
    long x = 0;
    int i = n;
    while (n) {
        x = x * 10 + n % 10;
        n /= 10;
    }
    return x == i;
}

int main(int argc, char **argv) {
    printf("%d\n", isPalindrome(strtol(argv[1], NULL, 10)));
    return 0;
}
