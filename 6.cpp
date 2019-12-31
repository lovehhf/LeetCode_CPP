
/*
 * 6. ZigZag Conversion
 * https://leetcode.com/problems/zigzag-conversion/

 * 画图找规律
 * 第一排和最后一排, 是一个等差数列, 公差为2 * (numRows - 1), 首项为i
   除第一排和最后一排是两个等差数列, 公差为2 * (numRows - 1), 首项分别为i, 2 * (numRows - 1) - i
 0     9     17
 1   810  1618
 2  7 11 15 19
 3 6  1214  20
 45   13    21...
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;

        for (int i = 0; i < numRows; i++) {
            int d = 2 * (numRows - 1);
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += d) {
                    res.push_back(s[j]);
                }
            } else {
                for (int j = i, k = d - i; j < s.size(); j += d, k += d) {
                    res.push_back(s[j]);
                    if (k < s.size()) res.push_back(s[k]);
                }
            }
        }

        return res;
    }
};