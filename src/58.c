#include <stdio.h>

int lengthOfLastWord(const char *s) {
    int l = 0, prev = 0;
    int i;
    for (i = 0; s[i]; ++i) {
        if (s[i] != ' ')
            ++l;
        else if (l) {
            prev = l;
            l = 0;
        }
    }
    return l ? l : prev;
}

int main(int argc, char *argv[]) {
    printf("%d\n", lengthOfLastWord(argv[1]));
    return 0;
}
