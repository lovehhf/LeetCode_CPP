
/* 69. x 的平方根
 * https://leetcode-cn.com/problems/sqrtx/
 *
 * 二分
 */


class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x  / 2 + 1;  // 先除2+1, 防止INT_MAX会溢出
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

