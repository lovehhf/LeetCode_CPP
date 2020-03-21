


/* 143. 重排链表
 * https://leetcode-cn.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if (!head) return;

        // 1. 找链表的中点(重排后的尾结点)
        ListNode *p = head, *q = head, *r;
        while(q && q->next) {
            p = p->next;
            q = q->next->next;
        }

        // 2. 翻转右半边的链表
        q = p->next;
        p->next = NULL;
        while(q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }

        // 3. 拼接两条链表 p: 1, 2, 3 q: 5, 4, 3
        q = head;
        while(q){
            r = q->next;
            q->next = p;
            q = p;
            p = r;
        }
    }
};