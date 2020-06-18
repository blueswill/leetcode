#include<stdio.h>
#include<string.h>
#include<limits.h>

int myAtoi(char *str) {
    char *b = str, *e = str + strlen(str);
    int r = 0;
    int t;
    int neg = 1;
    while(b < e && *b == ' ')
        ++b;
    if (b == e)
        return r;
    t = *b;
    if (t == '+')
        ++b;
    else if (t == '-') {
        neg = -1;
        ++b;
    }
    t = *b;
    if (t >= '0' && t <= '9') {
        r = neg * (t - '0');
        ++b;
    }
    else
        return 0;
    while ((t = *b++)) {
        //r * 10 - (t - '0') >= INT_MIN && r * 10 + (t - '0') <= INT_MAX
        if (t >= '0' && t <= '9') {
            int u = t - '0';
            if (neg > 0) {
                if (r <= (INT_MAX - u) / 10)
                    r = r * 10 + u;
                else
                    return INT_MAX;
            }
            else {
                if (r >= (INT_MIN + u) / 10)
                    r = r * 10 - u;
                else
                    return INT_MIN;
            }
        }
        else
            break;
    }
    return r;
}

int main(int argc, char **argv) {
    printf("%d\n", myAtoi(argv[1]));
    return 0;
}
