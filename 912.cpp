

/* 912. 排序数组
 * https://leetcode-cn.com/problems/sort-an-array/
 *
 */

class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1, x = nums[l], i = l - 1, j = r + 1;
        while(i < j) {
            do {i ++;} while (nums[i] < x);
            do {j --;} while (nums[j] > x);
            if(i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};