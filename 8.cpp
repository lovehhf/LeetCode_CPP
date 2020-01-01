
/* 8. String to Integer (atoi)
 * https://leetcode.com/problems/string-to-integer-atoi/
 * 
 * 第7题升级版
 * 主要的难点还是和第7题一样, 假设只能存32位有符号整数
 * 
 */

class Solution {
public:
    int myAtoi(string str) {
        int res = 0, n = str.size();
        int i = 0, sign = 1;

        // 去掉前面的空格 
        while (i < n && str[i] == ' ') {
            i++;
        }

        // 处理符号位 坑点: 符号位不止有 - 还有 + 
        if (i < n && (str[i] =='-' || str[i] == '+')) {
            sign = str[i ++] == '-' ? -1 : 1;
        }

        while (i < n) {
            if ('0' > str[i] || '9' < str[i]) break;
            int t = str[i] - '0';

            // 提前判断正溢出, 第7题的核心思想, 最后的值会溢出提前返回
            if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && t >= INT_MAX % 10)))
                return INT_MAX;
            
            // 提前判断负溢出, 需要注意 使用 -t <= INT_MIN % 10, 等于INT_MIN也提前返回, 否则会导致后面int存不下2^31
            if (sign == -1 && (res * sign < INT_MIN / 10 || (res * sign == INT_MIN / 10 && -t <= INT_MIN % 10)))
                return INT_MIN;

            res = res * 10 + t;
            i ++;
        }

        return sign * res;
    }
};