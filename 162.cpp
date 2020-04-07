
/* 162. 寻找峰值
 *
 * 二分
 * 如果 nums[mid - 1] > nums[mid] 那么在 0 ~ mid - 1 一定存在一个峰值
 * 反之 nums[mid - 1] < nums[mid] 在 mid ~ n - 1 一定存在一个峰值
 *
 * 每次砍掉一半的范围, 最后剩下的元素一定会是 一个峰值
 */


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > nums[mid - 1]) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};