

/** 
 * 3. Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 **/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        // 哈希表记录字母出现的次数, 如果都是小写字母可以使用数组代替
        unordered_map<char, int> dict;
        // 双指针 + 哈希 实现滑动窗口, i为滑动窗口右边界, j为滑动窗口左边界
        for(int i = 0, j = 0; i < s.size(); i ++)
        {
            dict[s[i]] ++;
            // dict[s[i]] > 1 表示出现了重复元素, 滑动窗口左边界向右移动, 直到滑动窗口中没有了重复元素
            while(dict[s[i]] > 1)
            {
                dict[s[j]] --;
                j ++;
            }
            res = max(res, i - j + 1);
        }
        
        return res;
    }
};