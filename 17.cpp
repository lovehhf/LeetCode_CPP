
/* 17. Letter Combinations of a Phone Number
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * dfs
 *
 * 还是python的列表推导式香...
 */



class Solution {
public:
    vector<string> res;
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &s, int i, string path) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }

        for (char c: map[s[i] - '0']) {
            dfs(s, i + 1, path + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        dfs(digits, 0, "");
        return res;
    }
};
