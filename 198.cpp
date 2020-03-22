
/* 198. 打家劫舍
 *
 * 动态规划
 * f[i]: 只考虑前 i 间房子, 最多能偷到多少钱
 * 状态转移方程: f[i] = max(f[i - 1], f[i - 1] + nums[i])
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if(n == 1) return nums[0];

        int f[n];  // f[i] 表示只考虑前 i 间房屋, 能偷到的最多的钱
        memset(f, 0, sizeof(int));
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i ++) {
            // f[i - 1]: 不偷第 i 家, f[i - 2] + nums[i] 偷第 i 家
            f[i] = max(f[i - 1], nums[i] + f[i - 2]);
        }

        return f[n - 1];
    }
};