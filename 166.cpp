
/* 166. 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
 *
 * 模拟除法运算
 * 使用哈希表存余数, 如果出现相同余数说明小数部分存在循环
 */

#define LL long long

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        LL num = numerator, denom = denominator;  // 转成long long, 否则 -2147483648 这个毒瘤转成正数会溢出

        string res = (num * denom < 0) ? "-" : ""; // 符号位
        num = abs(num);
        denom = abs(denom);

        // 哈希表存余数和对于的小数所在的位置, 余数出现相同的话那说明出现饿了循环节, 出现位置之后的就是循环节
        unordered_map<int, int> ht;

        LL n = num / denom, m = num % denom;
        res += to_string(n);

        if(!m) return res; // 可以整除, 直接返回

        res = res + '.';
        string dec = "";  // 小数部分
        int cur = 0; // 当前的小数位数
        while (m && ht.find(m) == ht.end()) {
            ht[m] = cur ++;
            m *= 10;
            n = m / denom;
            m = m % denom;
            dec += n + '0';
        }
        if (m) {
            // 存在循环, 插入循环节两边的括号
            dec.insert(ht[m], "(");
            dec += ")";
        }

        res = res + dec;
        return res;
    }
};