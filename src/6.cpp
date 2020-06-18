#include <string>

using std::string;

class Solution {
    public:
        string convert(string s, int numRows) {
            string res;
            if (numRows == 1)
                return s;
            res.reserve(s.size());
            int n = (numRows << 1);
            for (int r = 0; r < numRows; ++r) {
                int i = r;
                while (i < (int)s.size()) {
                    res.push_back(s[i]);
                    int j = i + n - 2 * (r + 1);
                    if (j < (int)s.size() && j != i && r != 0)
                        res.push_back(s[j]);
                    i += n - 2;
                }
            }
            return res;
        }
};
