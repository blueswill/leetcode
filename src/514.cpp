#include <vector>
#include <climits>
#include <string>
#include <set>

using namespace std;

class Solution {
    public:
        vector<int> tb[26];
        /* dp[i][j]: ring在第j个位置时旋转出key[i..]的最少步骤数 */
        int dp[100][100];
        void init(const string &key) {
            for (unsigned i = 0; i < key.size(); ++i)
                tb[key[i] - 'a'].push_back(i);
        }
        int findRotateSteps(string ring, string key) {
            init(ring);
            char b = key.back();
            for (unsigned j = 0; j < ring.size(); ++j) {
                int r = b - 'a';
                int res = INT_MAX;
                for (unsigned k = 0; k < tb[r].size(); ++k) {
                    int p = abs(tb[r][k] - (int)j);
                    res = min(res, min(p, (int)ring.size() - p));
                }
                dp[key.size() - 1][j] = res;
            }
            for (int i = (int)key.size() - 2; i >= 0; --i) {
                for (unsigned j = 0; j < ring.size(); ++j) {
                    int r = key[i] - 'a';
                    int res = INT_MAX;
                    for (unsigned k = 0; k < tb[r].size(); ++k) {
                        int step = abs(tb[r][k] - (int)j), next = tb[r][k];
                        step = min(step, (int)ring.size() - step);
                        res = min(res, step + dp[i + 1][next]);
                    }
                    dp[i][j] = res;
                }
            }
            return dp[0][0] + key.size();
        }
};

int main(void) {
    Solution s;
    int res = s.findRotateSteps("godding", "gd");
    return 0;
}
