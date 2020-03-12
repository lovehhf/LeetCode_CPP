

/* 128. 最长连续序列
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/
 *
 * 思路: 1. 使用集合存储 nums 中的所有元素, 集合的查找时间复杂度为 O(1)
 *         遍历数组, 遇到 num - 1 不在集合中才开始从集合中查找元素是否在集合中, 在集合中则长度 + 1
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num:nums) set.insert(num);

        int res = 0;
        for(int num:nums) {
            // 从连续序列的最小值开始算
            if(set.find(num - 1) == set.end()) {
                int tmp = num;
                while(set.find(tmp) != set.end()) tmp ++;
                res = max(res, tmp - num);
            }
        }

        return res;
    }
};