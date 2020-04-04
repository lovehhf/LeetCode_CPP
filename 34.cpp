
/* 34. 在排序数组中查找元素的第一个和最后一个位置
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 * 二分模板, 找 >= x 的左边界, 以及找 <= x 的右边界
 */


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int l = 0, r = nums.size() - 1;
        vector<int> res(2, -1);
        while(l < r) {
            // >= target 左边界
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[l] != target) return res;

        res[0] = l;
        l = 0;
        r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        res[1] = l;
        return res;
    }
};