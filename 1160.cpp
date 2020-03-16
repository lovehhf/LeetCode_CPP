
/*
 * 1160. 拼写单词
 * 链接: https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
 *
 * 使用哈希表 ht1 记录 chars 每个字符出现的次数, 复制到ht2, 遍历 word, 如果从ht2中减去相应字符出现的次数, 如果< 0了则说明该字符不够用
 *
 */


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> ht1, ht2;
        for (char c:chars) ht1[c] ++;

        int res = 0;
        for (string word: words) {
            ht2 = ht1;
            int tmp = word.size();
            for (char c:word) {
                if(--ht2[c] < 0) {
                    tmp = 0;
                    break;
                }
            }

            res += tmp;
        }

        return res;
    }
};