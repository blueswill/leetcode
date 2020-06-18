#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    private:
        string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string target;
        vector<string> res;

        void search(int cur, string acc) {
            if (cur == target.size()) {
                res.push_back(acc);
                return;
            }
            const string &p = m[target[cur] - '0'];
            for (unsigned i = 0; i < p.size(); ++i) {
                acc.push_back(p[i]);
                search(cur + 1, acc);
                acc.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty())
                return {};
            res.clear();
            string tmp;
            target = digits;
            search(0, tmp);
            return res;
        }
};
