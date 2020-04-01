

/* 49. 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/
 *
 * 字母异位词: 排序之后都一样
 * 
 * 使用哈希map存所有的字母异分词
 */



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> ht;
        
        for(string str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            ht[tmp].push_back(str);
        }

        for (auto item:ht) res.push_back(item.second);
        
        return res;
    }
};