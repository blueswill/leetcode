#include <vector>

using namespace std;

class Solution {
    public:
        void spread(vector<vector<char>> &board, int i, int j) {
            if ( i >= 0 && i < (int)board.size() &&
                 j >= 0 && j < (int)board[i].size() &&
                 board[i][j] == 'O') {
                board[i][j] = 'I';
                spread(board, i, j - 1);
                spread(board, i, j + 1);
                spread(board, i + 1, j);
                spread(board, i - 1, j);
            }
        }
        void solve(vector<vector<char>>& board) {
            unsigned i, j;
            if (board.size() == 0)
                return;
            for (i = 0; i < board.size(); ++i) {
                spread(board, i, 0);
                spread(board, i, board[i].size() - 1);
            }
            for (i = 0; i < board[0].size(); ++i) {
                spread(board, 0, i);
            }
            for (i = 0; i < board.back().size(); ++i) {
                spread(board, board.size() - 1, i);
            }
            for (i = 0; i < board.size(); ++i) {
                for (j = 0; j < board[i].size(); ++j) {
                    if (board[i][j] == 'I')
                        board[i][j] = 'O';
                    else if (board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
        }
};
