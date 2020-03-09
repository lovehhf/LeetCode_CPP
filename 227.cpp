
/* 227. 基本计算器 II
 * https://leetcode-cn.com/problems/basic-calculator-ii/
 */


class Solution {
public:
    void computer(stack<int> &nums, stack<char> &ops) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        int res = 0;
        if (op == '+') res = a + b;
        else if(op == '-') res = b - a;
        else if(op == '*') res = a * b;
        else res = b / a;

        nums.push(res);
    }

    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        int n = s.size();
        for(int i = 0; i < n; i ++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0, j = i;

                while(s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 - '0' + s[j];
                    j ++;
                }
                nums.push(num);
                // 先解决了乘除
                if (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) computer(nums, ops);
                i = j - 1;               
            } else {
                // 操作符已经没有了*/, 计算+-
                if (!ops.empty() && (s[i] == '+' || s[i] == '-')) computer(nums, ops);
                ops.push(s[i]);
            }
        }

        // 可能还有一步+-没有计算到
        if (!ops.empty()) computer(nums, ops);

        return nums.top();
    }
};