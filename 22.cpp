/* 
 * 22. Generate Parentheses
 * https://leetcode.com/problems/generate-parentheses/
 * 
 * 
暴力太惨了
Runtime: 40 ms, faster than 6.30%
Memory Usage: 32.6 MB, less than 5.79%
class Solution {
public:
    vector<string> res;
    
    int pre_sum(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') ret ++;
            if (s[i] == ')') ret --;
            if (ret < 0) return -1;
        }
        return ret;
    }
    
    void dfs(int i, int n, string path) {
        if (i == 2 * n) {
            if (pre_sum(path) == 0) res.push_back(path);
            return;
        }
        if (pre_sum(path + "(") >= 0)
            dfs(i + 1, n, path + '(');
        if (pre_sum(path + ")") >= 0)
            dfs(i + 1, n, path + ')');
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(0, n, "");
        return res;
    }
};
*/