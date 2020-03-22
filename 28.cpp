

/* 28. 实现 strStr()
 * https://leetcode-cn.com/problems/implement-strstr/
 *
 */


class Solution {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;

        int m = s.size(), n = p.size();
        vector<int> ne(n + 1, 0);
        s = ' ' + s;
        p = ' ' + p;

        // 求 next 数组, ne[i]: 模式串 p 最多可以往前移动几位(1392. 最长快乐前缀)
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && p[i] != p[j + 1]) j = ne[j]; // 匹配失败, 模式串继续往前移
            if (p[i] == p[j + 1]) j++; // 匹配成功, i++, j++ 继续匹配下一个字符
            ne[i] = j;
        }

        // s 和 p 开始匹配
        for (int i = 1, j = 0; i <= m; i++) {
            while (j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) j++;
            if (j == n) return i - n;
        }

        return -1;
    }
};
