

/* 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/

暴力做法, 时间复杂度O(N^2) Timeout
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i = 1; i < n; i ++)
            for(int j = 0; j < i; j++)
            {
                res = max(res, min(height[i], height[j]) * (i - j)); 
            }
        return res;
    }
};


双指针做法:
用两个指针 i,j 分别指向首尾，如果 ai>aj，则 j−−；否则 i++，直到 i=j 为止，每次迭代更新最大值, 时间复杂度O(n)

证明: 反证法，参考: https://www.acwing.com/solution/LeetCode/content/100/
*/


class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if (height[l] <= height[r]) l++;
            else r--;
        }
        return res;
    }
};
