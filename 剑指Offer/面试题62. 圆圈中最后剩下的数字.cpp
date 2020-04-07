


/*
 面试题62. 圆圈中最后剩下的数字
 https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

 约瑟夫环问题, 递推
 */

class Solution {

public:
    unordered_map<int, int> ht;

    int lastRemaining(int n, int m) {
        // f[n][m] = (f[n - 1][m] + m) % n

        int res = 0;
        for (int i = 2; i <= n; i ++) res = (res + m) % i;

        return res;
    }
};