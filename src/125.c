#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s) {
    char *f = s, *b = s + strlen(s) - 1;
    while (f < b) {
        if (((*f >= '0' && *f <= '9') || (*f >= 'A' && *f <= 'Z') ||
             (*f >= 'a' && *f <= 'z')) &&
            ((*b >= '0' && *b <= '9') || (*b >= 'A' && *b <= 'Z') ||
             (*b >= 'a' && *b <= 'z'))) {
            if (*f >= 'a' && *f <= 'z')
                if (*f != *b && *f != *b - 'A' + 'a')
                    return false;
            if (*f >= 'A' && *f <= 'Z')
                if (*f != *b && *f != *b - 'a' + 'A')
                    return false;
            if (*f >= '0' && *f <= '9')
                if (*f != *b)
                    return false;
            ++f;
            --b;
        }
        else if (((*f >= '0' && *f <= '9') || (*f >= 'A' && *f <= 'Z') ||
                  (*f >= 'a' && *f <= 'z')))
            --b;
        else
            ++f;
    }
    return true;
}
