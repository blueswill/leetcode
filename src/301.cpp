#include <vector>
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

class Solution {
    public:
        /* min_number[i][j]: s[i..j)的最小删除个数 */
        vector<vector<int>> min_number;
        vector<int> table;
        string str, bb;

        void cal_min_number() {
            unsigned l, i, b, k;
            /* s[i..i)空串 */
            for (i = 0; i <= bb.size(); ++i)
                min_number[i][i] = 0;
            /* l: 长度 - 1 */
            for (l = 0; l < bb.size(); ++l) {
                for (b = 0; b + l < bb.size(); ++b) {
                    unsigned i = b, e = b + l + 1; /* 右开 */
                    min_number[b][e] = 0;
                    while (i < e && bb[i] == ')') {
                        ++i; ++min_number[b][e];
                    }
                    if (i != b)
                        min_number[b][e] += min_number[i][e];
                    else {
                        int c = INT_MAX;
                        /* 搜索和第一个'('匹配的')' */
                        for (k = b + 1; k < e; ++k) {
                            if (bb[k] == ')') {
                                c = min(c, min_number[b + 1][k] + min_number[k + 1][e]);
                            }
                        }
                        /* 删去第一个'(' */
                        min_number[b][e] += min(c, min_number[b + 1][e] + 1);
                    }
                }
            }
        }

        vector<vector<bool>> parse(int b, int e, vector<vector<bool>> wait) {
            if (e <= b)
                return wait;
            int i = b, k, c = 0;
            vector<vector<bool>> res;
            while (i < e && bb[i] == ')') {
                ++c; ++i;
            }
            if (i != b)
                return parse(i, e, wait);
            if (min_number[b][e] == min_number[b + 1][e] + 1) {
                auto p = parse(b + 1, e, wait);
                res.insert(res.end(), p.begin(), p.end());
            }
            /* c = 0 */
            for (auto &t : wait)
                t[b] = true;
            for (k = b + 1; k < e; ++k) {
                if (bb[k] == ')' &&
                    min_number[b][e] == min_number[b + 1][k] + min_number[k + 1][e]) {
                    for (auto &t : wait)
                        t[k] = true;
                    auto p = parse(b + 1, k, wait);
                    p = parse(k + 1, e, p);
                    res.insert(res.end(), p.begin(), p.end());
                    for (auto &t : wait)
                        t[k] = false;
                }
            }
            return res;
        }

        string transfer(const vector<bool> &m) {
            string res = str;
            for (int i = (int)m.size() - 1; i >= 0; --i) {
                if (m[i] == false)
                    res.erase(table[i], 1);
            }
            return res;
        }

        string handle() {
            string r;
            for (unsigned i = 0; i < str.size(); ++i) {
                if (str[i] == '(' || str[i] == ')') {
                    r.push_back(str[i]);
                    table[r.size() - 1] = i;
                }
            }
            return r;
        }
        vector<string> removeInvalidParentheses(string s) {
            min_number.clear();
            table = vector<int>(s.size());
            str = s;
            bb = handle();
            min_number = vector<vector<int>>(s.size() + 1, vector<int>(bb.size() + 1, -1));
            cal_min_number();
            auto m = parse(0, bb.size(), {vector<bool>(bb.size(), false)});
            set<string> res;
            for (auto &t : m) {
                res.insert(transfer(t));
            }
            return vector<string>(res.begin(), res.end());
        }
};

int main(void) {
    Solution s;
    string test = ")(";
    auto res = s.removeInvalidParentheses(test);
    for (auto m : res)
        cout << m << endl;
    return 0;
}
