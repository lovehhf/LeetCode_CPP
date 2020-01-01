
/* 10. Regular Expression Matching
 * https://leetcode.com/problems/regular-expression-matching/
 * 正则表达式匹配      , 经典的dp问题
 */


class Solution {
public:
    bool isMatch(string s, string p) {
        s = ' ' + s;
        p = ' ' + p;
        uint32_t n = s.size(), m = p.size();

        // f[i][j]: s的前i个字母能否被 p 的前j个字母表示
        vector<vector<bool>> f(n, vector<bool>(m, false));

        f[0][0] = true;

        // p匹配s为空的情况
        for (int i = 2; i < m; i++) {
            if (p[i] == '*') f[0][i] = f[0][i - 2];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // 正常转移
                if (s[i] == p[j] || p[j] == '.') {
                    f[i][j] = f[i - 1][j - 1];
                }

                // 带 * 的转移
                if (p[j] == '*') {
                    // * 匹配0次前一个字符
                    f[i][j] = f[i][j - 2];
                    // * 匹配一次以上前一个字符
                    if (s[i] == p[j - 1] || p[j - 1] == '.') {
                        f[i][j] = f[i][j] || f[i - 1][j];
                    }
                }
            }
        }

        return f[n - 1][m - 1];
    }
};
