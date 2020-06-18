#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<vector<bool>> left_top;
        vector<vector<bool>> right_bottom;
        unsigned m, n;
        void dfs(vector<vector<bool>> &mm, unsigned i, unsigned j, const vector<vector<int>> &data) {
            mm[i][j] = true;
            if (j > 0 && !mm[i][j - 1] && data[i][j - 1] >= data[i][j])
                dfs(mm, i, j - 1, data);
            if (i > 0 && !mm[i - 1][j] && data[i - 1][j] >= data[i][j])
                dfs(mm, i - 1, j, data);
            if (i + 1 < m && !mm[i + 1][j] && data[i + 1][j] >= data[i][j])
                dfs(mm, i + 1, j, data);
            if (j + 1 < n && !mm[i][j + 1] && data[i][j + 1] >= data[i][j])
                dfs(mm, i, j + 1, data);
        }
        vector<vector<int>> pacificAtlantic(const vector<vector<int>>& matrix) {
            if (matrix.empty())
                return {};
            res.clear();
            left_top = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size(), false));
            right_bottom = left_top;
            m = matrix.size(), n = matrix[0].size();
            for (unsigned i = 0; i < m; ++i) {
                if (!left_top[i][0])
                    dfs(left_top, i, 0, matrix);
                if (!right_bottom[i][n - 1])
                    dfs(right_bottom, i, n - 1, matrix);
            }
            for (unsigned i = 0; i < n; ++i) {
                if (!left_top[0][i])
                    dfs(left_top, 0, i, matrix);
                if (!right_bottom[m - 1][i])
                    dfs(right_bottom, m - 1, i, matrix);
            }
            for (unsigned i = 0; i < m; ++i) {
                for (unsigned j = 0; j < n; ++j)
                    if (left_top[i][j] && right_bottom[i][j])
                        res.push_back({(int)i, (int)j});
            }
            return res;
        }
};

int main(void) {
    Solution s;
    s.pacificAtlantic({{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}});
    return 0;
}
