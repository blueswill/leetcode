#include <vector>

using namespace std;

int vec[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

class Solution {
    public:
        vector<vector<int>> res;
        void dfs(const vector<vector<int>> &m, int i, int j) {
            res[i][j] = INT_MIN;
            for (int s = 0; s < 4; ++s) {
                int it = i + vec[s][0], jt = j + vec[s][1];
                if (it >= 0 && it < (int)m.size() &&
                    jt >= 0 && jt < (int)m[it].size() &&
                    m[it][jt] > m[i][j]) {
                    if (res[it][jt] < 0)
                        dfs(m, it, jt);
                    res[i][j] = max(res[i][j], res[it][jt] + 1);
                }
            }
            if (res[i][j] < 0)
                res[i][j] = 1;
        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            res.clear();
            res.resize(matrix.size());
            if (res.size() == 0)
                return 0;
            for (unsigned i = 0; i < matrix.size(); ++i)
                res[i] = vector<int>(matrix[i].size(), -1);
            int r = INT_MIN;
            for (unsigned i = 0; i < matrix.size(); ++i) {
                for (unsigned j = 0; j < matrix[i].size(); ++j) {
                    if (res[i][j] < 0)
                        dfs(matrix, (int)i, (int)j);
                    r = max(r, res[i][j]);
                }
            }
            return r;
        }
};
