


/* 38. 外观数列
 * 
 * https://leetcode-cn.com/problems/count-and-say/
 * 
 * 双指针实现滑动窗口
 */

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for(int i = 2; i <= n; i ++) {
            int j = 0, k = 0;
            string s  = "";
            while(j < res.size()) {
                while (j < res.size() && res[j] == res[k]) j ++;
                s += to_string(j - k); // 出现次数
                s += res[k];  // 出现的数字
                k = j;
            }
            res = s;
        }

        return res;
    }
};