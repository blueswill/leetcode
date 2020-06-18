bool string_cmp(const string &a, const string &b) {
    return a.size() < b.size();
}

struct node {
    node *next[26];
    bool valid;
    node() : next(), valid(false) {}
};

class Solution {
    public:
        node root;
        bool dfs(const string &s, unsigned cur_start) {
            if (cur_start == s.size())
                return true;
            node *cur = &root;
            for (unsigned i = cur_start; i < s.size(); ++i) {
                cur = cur->next[s[i] - 'a'];
                if (!cur)
                    return false;
                if (cur->valid && dfs(s, i + 1))
                    return true;
            }
            return false;
        }
        bool check(const string &s) {
            node *cur = &root;
            for (unsigned i = 0; i < s.size(); ++i) {
                if (!cur->next[s[i] - 'a'])
                    cur->next[s[i] - 'a'] = new node;
                cur = cur->next[s[i] - 'a'];
                if (cur->valid && dfs(s, i + 1))
                    return true;
            }
            cur->valid = true;
            return false;
        }
        void free_all(node *cur) {
            for (int i = 0; i < 26; ++i) {
                if (cur->next[i])
                    free_all(cur->next[i]);
                delete cur->next[i];
            }
        }
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            sort(words.begin(), words.end(), string_cmp);
            vector<string> res;
            for (string &s : words)
                if (check(s))
                    res.push_back(s);
            free_all(&root);
            return res;
        }
};