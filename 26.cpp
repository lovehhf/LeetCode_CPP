
/*
 * 26. Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * 双指针, i 指向不重复的数组的最后一个 index, j 用来遍历数组
 *        nums[i] == nums[j] 时, j += 1, 否则将 nums[j] 赋值给 nums[i + 1]
 *1. [0,0,1,1,1,2,2,3,3,4]
      i   j
  2. [0,1,1,1,1,2,2,3,3,4]
        i j---->j
  3. [0,1,2,1,1,2,2,3,3,4]
          i     j-->j
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] == nums[i])
                j ++;
            else {
            	// 这里 i 一定是 < j 的, 没有在里面做 j++ 的操作, j 一定会 < n, 不会出现越界的情况
            	// 所以不需要加 j < n && i + 1 < n 的判断
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};