#include<set>
#include<string>
#include<assert.h>
#include<iostream>
#include<cstring>

using std::string;

struct Regex {
#define TOKEN   0
#define TARGET  1
#define nothing 0
#define null    1
    int (*rotate)[2];
    int (*forward)[2];
    std::set<int> *null_set;
    int END; /* end state */
};


int star(const char *p, int s) {
    while (p[s] == '*')
        ++s;
    return s;
}

Regex *regex_init(const char *pattern) {
    Regex *r = new Regex;
    int s = strlen(pattern);
    r->rotate = new int[s + 1][2]{};
    r->forward = new int[s + 1][2]{};
    r->null_set = new std::set<int>[s + 1];
    int cur = 0;
    for (int i = 0; i < s; ++i) {
        assert(pattern[i] != '*');
        int n = star(pattern, i + 1);
        r->forward[cur][TARGET] = cur + 1;
        if (n != i + 1) {
            r->rotate[cur][TOKEN] = pattern[i];
            r->rotate[cur][TARGET] = cur;
            r->forward[cur][TOKEN] = null;
        }
        else
            r->forward[cur][TOKEN] = pattern[i];
        ++cur;
        i = n - 1;
    }
    r->END = cur;
    r->null_set[r->END].insert(r->END);
    for (int i = r->END; i >= 0; --i) {
        r->null_set[i].insert(i);
        if (r->forward[i][TOKEN] == null) {
            r->null_set[i].insert(i + 1);
            r->null_set[i].insert(r->null_set[i + 1].begin(), r->null_set[i + 1].end());
        }
    }
    return r;
}

void regex_destroy(Regex *r) {
    delete[] r->forward;
    delete[] r->null_set;
    delete[] r->rotate;
    delete r;
}

bool match(char s, char p) {
    if (p == null)
        return false;
    return p == '.' || s == p;
}

bool regex_match(Regex *r, const char *s) {
    std::set<int> prev = r->null_set[0];
    for (int i = 0; s[i]; ++i) {
        std::set<int> cur;
        for (int e : prev) {
            if (match(s[i], r->forward[e][TOKEN]))
                cur.insert(r->forward[e][TARGET]);
            if (match(s[i], r->rotate[e][TOKEN]))
                cur.insert(r->rotate[e][TARGET]);
        }
        std::set<int> f;
        for (int e : cur)
            f.insert(r->null_set[e].begin(), r->null_set[e].end());
        prev = f;
    }
    return prev.find(r->END) != prev.end();
}

class Solution {
    public:
        bool isMatch(string s, string p) {
            Regex *r = regex_init(p.c_str());
            bool f = regex_match(r, s.c_str());
            regex_destroy(r);
            return f;
        }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << s.isMatch(argv[2], argv[1]) << std::endl;
    return 0;
}
