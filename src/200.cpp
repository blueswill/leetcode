#include <vector>

using namespace std;

class Solution {
    public:
        void dfs(vector<vector<char>> &grid, int i, int j) {
            if (i >= 0 && i < (int)grid.size() &&
                j >= 0 && j < (int)grid[i].size() &&
                grid[i][j] == '1') {
                grid[i][j] = '0';
                dfs(grid, i - 1, j);
                dfs(grid, i + 1, j);
                dfs(grid, i, j - 1);
                dfs(grid, i, j + 1);
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int r = 0;
            unsigned i, j;
            for (i = 0; i < grid.size(); ++i) {
                for (j = 0; j < grid[i].size(); ++j) {
                    if (grid[i][j] == '1') {
                        ++r;
                        dfs(grid, i, j);
                    }
                }
            }
            return r;
        }
};
