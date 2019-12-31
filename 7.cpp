


/* 7. Reverse Integer
https://leetcode.com/problems/reverse-integer/

下面是错误的做法
需要返回的值是int类型, 返回的是long 虽然能过, 但是和题意不符

并且还假设了环境只能存储得下 32 位的有符号整数

不让用 long 题目难度还是easy过分了...

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < pow(-2, 31) || res > pow(2, 31) - 1) return 0;
        return res;
    }
};


这个溢出判断不行, 溢出直接报错抛异常了
t = res * 10 + x % 10;
if ((res > 0 && t < res) || (res < 0 && t > res)) return 0;


需要在 * 10 之前和 INT_MAX/10 与 INT_MIN/10 比较看是否会溢出
if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && t > 7)) ||
     res < INT_MIN / 10 || (res == INT_MIN / 10 && t < -8))
     return 0;

由于x是int类型, res == INT_MAX / 10 && t > 7 和 res == INT_MIN / 10 && t < -8 这两种判断条件不可能存在,
可以直接写成 if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0; 
*/


class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int t;
        while (x) {
            t = x % 10;
            // 在溢出之前提前判断
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            res = res * 10 + t;
            x /= 10;
        }
        return res;
    }
};