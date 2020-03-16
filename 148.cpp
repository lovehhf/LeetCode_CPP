

/* 148. 排序链表
 * 原题链接: https://leetcode-cn.com/problems/sort-list/
 *
 * 三路快排, < 头节点的节点放左边, = 头节点的节点放右边, > 头节点的节点放右边
 * 递归左右两边
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *left = new ListNode(-1);   // 左边的链表值 < x
        ListNode *mid = new ListNode(-1);    // 中间的链表值 = x
        ListNode *right = new ListNode(-1);  // 右边的链表值 > x
        ListNode *ltail = left, *mtail = mid, *rtail = right;

        int val = head->val;
        for (ListNode *p = head; p; p = p->next) {
            // 三路快排 partition
            if (p->val < val) ltail = ltail->next = p;
            else if(p->val == val) mtail = mtail->next = p;
            else rtail = rtail->next = p;
        }

        ltail->next = mtail->next = rtail->next = NULL;

        left->next = sortList(left->next);
        right->next = sortList(right->next);

        // 拼接链表, 这里不能直接用 tail, 因为排完序之后tail就不在最后了
        ListNode *p = left, *q = mid;
        while(p->next) p = p->next;
        while(q->next) q = q->next;
        p->next = mid->next;
        q->next = right->next;

        return left->next;
    }
};