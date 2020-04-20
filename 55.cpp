
/* 55. 跳跃游戏
 * https://leetcode-cn.com/problems/jump-game/
 *
 * 贪心:
 *
 * 逆推:
 * 如果从当前位置能够跳到最后一个位置，那就可以把后部分截掉，变成能否从开头跳到当前位置
 *
 * 正推:
 *
 * 计算最远能跳到的距离, 遍历一遍看是否能跳到终点, 中间某个点跳不到直接返回
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = nums.size() - 1;  // 终点

        for (int i = n - 2; ~i; i --) {
            if (i + nums[i] >= end) {
                // 从 i 号点可以跳到终点, 这个点变为新的终点
                // 前面的点只需要能跳到这个点就一定可以跳到终点
                end = i;
            }
        }

        // 终点变为开头说明从 0 号点可以跳到 n - 1 号点
        return !end;
    }
};