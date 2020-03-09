
/* 224. 基本计算器
 * https://leetcode-cn.com/problems/basic-calculator/
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
        if (op == '+') nums.push(a + b);
        else nums.push(b - a);
    }
    
    int calculate(string s) {
        
        stack<char> ops;  // 操作符栈
        stack<int> nums;  // 数字栈
        int n = s.size();
        
        for(int i = 0; i < n; i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                int j = i;
                while(j < n && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 - '0' + s[j];
                    j ++;
                }
                nums.push(num);
                if (!ops.empty() && ops.top() != '(') computer(nums, ops);
                i = j - 1;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                ops.push(s[i]);
            } else if (s[i] == ')') {
                // 遍历到)时ops栈顶一定会是(
                ops.pop();
                if (!ops.empty() && ops.top() != '(') computer(nums, ops);
            }
        }
        
        return nums.top();
    }
};