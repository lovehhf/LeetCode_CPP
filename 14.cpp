
/* 14. Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/
 * python的reduce
 */


class Solution {
public:
    // 字符串a和b的公共前缀
    string common_prefix(string &a, string &b)
    {
        int m = a.size(), n = b.size();
        string ret;
        for(int i = 0; i < min(m,n); i ++)
        {
            if (a[i] != b[i]) break;
            ret.push_back(a[i]);
        }
        return ret;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n) return "";
        
        string res = strs[0];
        
        for(int i = 1; i < n; i++)
        {
            res = common_prefix(res, strs[i]);
        }
        return res;
    }
};