
/* 5. Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/
 * 中心扩展算法 时间复杂度O(n^2), 空间复杂度O(1)
 */


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            // abcba型回文串
            for (int j = 0; i - j >= 0 && i + j < n; j++) {
                if (s[i - j] != s[i + j]) break;
                if (2 * j + 1 > res.size()) res = s.substr(i - j, 2 * j + 1);
            }

            // abba回文串
            for (int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
                if (s[i - j] != s[i + j + 1]) break;
                if (2 * j + 2 > res.size()) res = s.substr(i - j, 2 * j + 2);
            }
        }
        return res;
    }
};