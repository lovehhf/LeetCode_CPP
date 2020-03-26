

/* 37. 解数独
 * https://leetcode-cn.com/problems/sudoku-solver/
 *
 *
 */

class Solution {
public:
    const int n = 9;
    bool row[9][9], col[9][9], squ[9][9];

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if(y == n) { // 列搜索到头了, 搜索下一行
            x ++;
            y = 0;
        }
        if(x == n) { // 解开了
            return true;
        }

        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 0; i < n; i ++) {
            if (row[x][i] || col[y][i] || squ[x / 3 * 3 + y / 3][i]) continue;

            row[x][i] = col[y][i] = squ[x / 3 * 3 + y / 3][i] = true;
            board[x][y] = '1' + i;

            if (dfs(board, x, y + 1)) return true;

            row[x][i] = col[y][i] = squ[x / 3 * 3 + y / 3][i] = false;
            board[x][y] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(squ, 0, sizeof squ);

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = col[j][num] = squ[i / 3 * 3 + j / 3][num] = true;
                }
            }

        dfs(board, 0, 0);
    }
};