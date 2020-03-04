
/* 238. Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self/
 *
 * 前缀积与后缀积
 * 第 i 个数的除自身以外数组的乘积 = 前 i - 1 个数的前缀积 *  i + 1 后面的数的后缀积
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int> &a) {
        int n = a.size();
        int t = 1;
        vector<int> b(n, 1);

        // 前 i - 1 个数的前缀积
        for (int i = 1; i < n; i++) {
            b[i] = b[i - 1] * a[i - 1];
        }

        // i + 1 之后的数的后缀积
        for (int i = n - 1; i >= 0; i--) {
            b[i] *= t;
            t *= a[i];
        }

        return b;
    }
};