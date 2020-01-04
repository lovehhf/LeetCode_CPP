
/** https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
 * 
 * 删除倒数第n个节点 -> 找到倒数第 n-1 个节点
 *
 * 快慢指针, 快指针先走 n + 1 步, 之后快慢指针一起走, 到快指针走完链表, 慢指针指向的就就是倒数第 n+1 个数 
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };0
 */


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 慢指针:p 快指针: q
        ListNode *p = new ListNode(-1);
        ListNode *q = head;
        p->next = head;
        // 虚拟头节点, 避免n=链表长度的情况
        ListNode *dummy = p;
        while (n --) q = q->next;
        while(q) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};