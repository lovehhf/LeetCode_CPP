
/* 945. 使数组唯一的最小增量
 * https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
 *
 * 排序之后遍历
 * 如果当前元素大于上一个元素，保持不变
 * 如果当前元素小于等于上一个元素，就需要增加当前元素，直到大于上一个元素
 */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;

        for(int i = 1; i < nums.size(); i ++) {
            if (nums[i] <= nums[i - 1]) {
                res += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return res;
    }
};