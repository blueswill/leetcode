#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <utility>

using namespace std;

class Solution {
    private:
        // char -> {init, acc}
        unordered_map<char, pair<unsigned, unsigned>> rec;
        unsigned mlen, start;
    public:
        string minWindow(string s, string t) {
            rec.clear();
            mlen = numeric_limits<unsigned>::max();
            if (t.empty())
                return "";
            for (char c : t) {
                ++rec[c].first;
            }
            unsigned num = 0;
            unsigned j = 0;
            for (unsigned i = 0; i < s.size(); ++i) {
                auto iter = rec.find(s[i]);
                if (iter == rec.end())
                    continue;
                ++iter->second.second;
                if (iter->second.first == iter->second.second)
                    ++num;
                for (; j < i; ++j) {
                    auto it = rec.find(s[j]);
                    if (it != rec.end() && it->second.second) {
                        if (it->second.second <= it->second.first)
                            break;
                        --it->second.second;
                    }
                }
                if (num >= rec.size() && mlen > i - j + 1) {
                    mlen = i - j + 1;
                    start = j;
                }
            }
            if (num < rec.size())
                return "";
            return s.substr(start, mlen);
        }
};

int main(void) {
    Solution s;
    s.minWindow("aaflslflsldkalskaaa", "aaa");
    return 0;
}
