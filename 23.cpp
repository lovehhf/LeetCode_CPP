


/** 23. 合并K个排序链表
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 顺序合并, 时间复杂度 O(K^2n), k 为数组大小, n 为最长链表长度
 * 先合并2条链表, 再用和结果和其他链表合并(reduce)
 *
 * 基于分支思想优化：
 * 类似归并排序, 每条链表只和相邻的链表合并
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* merge2Lists(ListNode *p, ListNode *q) {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while (p && q) {
            if(p->val < q->val) {
                head->next = p;
                p = p->next;
            } else {
                head->next = q;
                q = q->next;
            }
            head = head->next;
        }
        if (p) head->next = p;
        if (q) head->next = q;
        return dummy->next;
    }

    // 分治, 每条链表只和与它相邻的链表合并, 时间复杂度O(log(n)), n为nlog(n), n为数组长度
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l >= r) return lists[l];
        int mid = (l + r) >> 1;
        ListNode *left = merge(lists, l, mid);
        ListNode *right = merge(lists, mid + 1, r);
        return merge2Lists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return lists.size() == 0 ? nullptr : merge(lists, 0, lists.size() - 1);
    }
};