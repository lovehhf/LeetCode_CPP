

/* 151. 翻转字符串里的单词
 * 
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/
 *  
 * 先翻转整体再翻转每个单词
 */

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";

        // 1. 整体翻转
        reverse(s.begin(), s.end());

        int i = 0, j = 0;
        while(i < n && s[i] == ' ') {
            i ++;
            j ++;
        }

        while(n - 1 > 0 && s[n - 1] == ' ') n --;
        
        while(i < n) {
            while(i < n && s[i] != ' ')  i ++;
            if (i != j) {
                // 2. 局部翻转
                reverse(s.begin() + j, s.begin() + i);
                res += s.substr(j, i - j);
                if (i < n) res += ' ';
            }

            j = ++i;            
        }

        return res;
    }
};