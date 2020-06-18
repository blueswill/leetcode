#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        // dp[i] is the maximum length of matched substring ending with s[i]
        vector<unsigned> dp;
    public:
        int longestValidParentheses(string s) {
            if (s.empty())
                return 0;
            dp = vector<unsigned>(s.size());
            dp[0] = 0;
            unsigned res = 0;
            for (unsigned i = 1; i < s.size(); ++i) {
                if (s[i] == '(')
                    dp[i] = 0;
                else {
                    int j = i - 1 - dp[i - 1];
                    if (j < 0)
                        dp[i] = 0;
                    else if (s[j] == '(') {
                        dp[i] = i - j + 1;
                        if (j > 0)
                            dp[i] += dp[j - 1];
                    }
                    else
                        dp[i] = 0;
                }
                res = max(res, dp[i]);
            }
            return (int)res;
        }
};
