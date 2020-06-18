#include <stdbool.h>

bool isIsomorphic(char *s, char *t) {
    char map[256] = {};
    char used[256] = {};
    for (int i = 0; s[i]; ++i) {
        if (!map[s[i]]) {
            if (used[t[i]])
                return false;
            map[s[i]] = t[i];
            used[t[i]] = true;
        }
        else if (map[s[i]] != t[i])
            return false;
    }
    return true;
}
