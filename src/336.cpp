#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

struct node {
    int index;
    node *next[26];

    node() : index(-1), next{nullptr} {}
};

class Solution {
    private:
        node root;
        vector<string> *w;
        void insert(const string &str, int i) {
            node *t = &root;
            for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
                if (!t->next[*iter - 'a'])
                    t->next[*iter - 'a'] = new node;
                t = t->next[*iter - 'a'];
            }
            t->index = i;
        }
        
        bool check(const string &a, const string &b, int i, int j) {
            if (i == (int)a.size()) {
                for (int s = 0; (s << 1) < j; ++s)
                    if (b[s] != b[j - s])
                        return false;
                return true;
            }
            for (int s = i; (s << 1) < (int)a.size() + i - 1; ++s)
                if (a[s] != a[a.size() - (s - i) - 1])
                    return false;
            return true;
        }

        void search(node *cur, int i, int consumed, vector<vector<int>> &res) {
            if (cur->index >= 0 && cur->index != i) {
                string &s = (*w)[cur->index];
                if (check((*w)[i], s, consumed, (int)s.size() - consumed - 1)) {
                    res.push_back({i, cur->index});
                }
            }
            for (int j = 0; j < 26; ++j)
                if (cur->next[j])
                    search(cur->next[j], i, consumed, res);
        }
    public:
        vector<vector<int>> palindromePairs(vector<string> &words) {
            vector<vector<int>> res;
            w = &words;
            for (int i = 0; i < (int)words.size(); ++i)
                insert(words[i], i);
            for (int i = 0; i < (int)words.size(); ++i) {
                const string &a = words[i];
                node *t = &root;
                for (int s = 0; s < (int)a.size() && t; ++s) {
                    if (t->index >= 0 && t->index != i && check(a, words[t->index], s, -1))
                        res.push_back({i, t->index});
                    int v = a[s] - 'a';
                    t = t->next[v];
                }
                if (t)
                    search(t, i, (int)a.size(), res);
            }
            return res;
        }
};

int main(void) {
    Solution s;
    vector<string> test{"abcd","dcba","lls","s","sssll"};
    auto result = s.palindromePairs(test);
    for (auto &res : result)
        printf("%d %d\n", res[0], res[1]);
    return 0;
}
