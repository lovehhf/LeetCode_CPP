

/* 445. 两数相加 II
 * https://leetcode-cn.com/problems/add-two-numbers-ii/
 *
 * 方法一: 反转链表， 变成第2题
 * 方法二: 用栈存链表
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        ListNode *p = l1, *q = l2;
        while(p) {
            stk1.push(p->val);
            p = p->next;
        }
        while(q) {
            stk2.push(q->val);
            q = q->next;
        }

        ListNode *dummy = new ListNode(-1);

        int carry = 0;
        while (stk1.size() || stk2.size()) {
            int x = 0, y = 0;
            if (stk1.size()) {
                x = stk1.top();
                stk1.pop();
            }
            if (stk2.size()) {
                y = stk2.top();
                stk2.pop();
            }
            int a = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            p = new ListNode(a);
            p->next = dummy->next;
            dummy->next = p;
        }

        if (carry) {
            p = new ListNode(carry);
            p->next = dummy->next;
            dummy->next = p;
        }

        return dummy->next;
    }
};