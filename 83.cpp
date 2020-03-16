
/* 83. 删除排序链表中的重复元素
 * 原题链接:https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 *
 */


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;

        while(p && p->next) {
            if (p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }

        return head;
    }
};