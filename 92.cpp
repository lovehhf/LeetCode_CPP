

/* 92. 反转链表 II
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/
 *
 * 局部翻转链表, 翻转 n - m 次
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *pre = dummy;
        int t = n - m;
        while(-- m) pre = pre->next;    // 找到第 m 个节点前面的节点

        ListNode *p = pre->next, *q = p->next, *r;

        // 循环 n - m 次, 翻转之后结果 1(pre) -> 2 -> <- 3 <- 4(p) -> 5(q, r)
        while(t --) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        // 拼接链表
        pre->next->next = q;
        pre->next = p;

        return dummy->next;
    }
};