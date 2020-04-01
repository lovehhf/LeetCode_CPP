

/* 53. 最大子序和
 * https://leetcode-cn.com/problems/maximum-subarray/
 *
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        int f[n];
        memset(f, 0, sizeof f);
        f[0] = nums[0];

        for(int i = 1; i < n; i ++) {
            f[i] = max(nums[i], f[i - 1] + nums[i]);
            res = max(res, f[i]);
        }

        return res;
    }
};