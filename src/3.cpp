#include <string>
#include <algorithm>

using std::string;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.empty())
                return 0;
            int tag[256];
            for (int i = 0; i < 256; ++i)
                tag[i] = -1;
            int res = 1, len = 1;
            tag[s[0]] = 0;
            for (unsigned index = 1; index < s.size(); ++index) {
                int v = s[index], l = len;
                if (tag[v] >= 0) {
                    l = index - tag[v] - 1;
                    for (int i = index - len; i <= tag[v]; ++i)
                        tag[s[i]] = -1;
                }
                tag[v] = index;
                len = l + 1;
                if (len > res)
                    res = len;
            }
            return res;
        }
};

int main(void) {
    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}
