

/* 289. 生命游戏
 *
 * https://leetcode-cn.com/problems/game-of-life/
 *
 * 位运算, 第一位表示当前状态, 第二位表示下一轮的状态
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 活细胞死亡: 01  死细胞复活 10  活细胞继续存活: 11  死细胞继续死亡: 00
        int m = board.size(), n = board[0].size();
        int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int cnt = 0;
                for (int k = 0; k < 8; k ++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (board[x][y] & 1) cnt ++;
                }
                if (board[i][j] == 1 && cnt >= 2 && cnt <= 3) board[i][j] = 3; // 活细胞继续存活
                if (board[i][j] == 0 && cnt == 3) board[i][j] = 2; // 死细胞复活
                // printf("%d %d %d %d\n", i, j, cnt, board[i][j]);
            }
        }

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j++)
                board[i][j] >>= 1;

    }
};