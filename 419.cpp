
/* 419. 甲板上的战舰
 * https://leetcode-cn.com/problems/battleships-in-a-board/
 * 思路: 只通过战舰的头判断, 如果 'X' 左边或上边也是 'X', 可以直接跳过
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X' || j > 0 && board[i][j - 1] == 'X') continue;
                    res ++;
                }
            }
        
        return res;
    }
};