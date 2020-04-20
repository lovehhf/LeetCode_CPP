

/*
 * 453. 最小移动次数使数组元素相等
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
 *
 * 每次移动可以使 n - 1 个元素增加 1, 等价于使 1 个元素 - 1
 */


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int min_v = nums[0];

        for (int num:nums) {
            if (min_v > num) min_v = num;
        }

        for(int num:nums) res += num - min_v;

        return res;
    }
};