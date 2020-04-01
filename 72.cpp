
/* 72. 编辑距离
 * https://leetcode-cn.com/problems/edit-distance/
 *
 * dp:
 * 状态表示: f[i][j] 表示 s1 前 i 个字母编辑到 s2 前 j 个字母需要编辑多少次
 * 状态转移： s1[i] == s[j]: 从 f[i - 1][j - 1] 转移, 不用编辑
 *           s1[i] != s2[j]: 从三种编辑方式(增/删/改)转移, 取最小值
 */




class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));

        word1 = ' ' + word1;
        word2 = ' ' + word2;
        for (int i = 1; i <= m; i ++) f[i][0] = i;
        for (int i = 1; i <= n; i ++) f[0][i] = i;

        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++) {
                if (word1[i] == word2[j]) f[i][j] = f[i - 1][j - 1];
                else {
                    f[i][j] = min(f[i - 1][j] , f[i][j - 1]) + 1;
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            }

        return f[m][n];
    }
};