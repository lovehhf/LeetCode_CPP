

/* 131. 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/
 *
 * 暴力回溯
 *
 * 可以预处理回文串做优化 
 */



class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool check(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l ++;
            r --;
        }
        return true;
    }

    void dfs(string s, int u) {
        if(u == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = u; i < s.size(); i++) {
            if (check(s, u, i)) {
                path.push_back(s.substr(u, i - u + 1));
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};