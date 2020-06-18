#include <vector>
#include <string>
#include <limits>

using namespace std;

class Solution {
    private:
        // dp[i][j]: the minimum distance of word1[0..i) and word2[0..j)
        vector<vector<unsigned>> dp;
    public:
        int minDistance(string word1, string word2) {
            if (word1.empty())
                return word2.size();
            if (word2.empty())
                return word1.size();
            dp = vector<vector<unsigned>>(word1.size() + 1, vector<unsigned>(word2.size() + 1));
            for (unsigned j = 0; j < dp[0].size(); ++j)
                dp[0][j] = j; //insert
            for (unsigned i = 0; i < dp.size(); ++i)
                dp[i][0] = i; //delete
            for (unsigned i = 0; i < word1.size(); ++i) {
                for (unsigned j = 0; j < word2.size(); ++j) {
                    unsigned m = numeric_limits<unsigned>::max();
                    //insert
                    m = min(m, dp[i + 1][j] + 1);
                    // delete
                    m = min(m, dp[i][j + 1] + 1);
                    if (word1[i] == word2[j])
                        m = min(m, dp[i][j]); //no action
                    else
                        m = min(m, dp[i][j] + 1);
                    dp[i + 1][j + 1] = m;
                }
            }
            return dp[word1.size()][word2.size()];
        }
};
