


/** 23. Merge k Sorted Lists
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * 先合并2条链表, 再用和结果和其他链表合并(reduce)
 * 时间复杂度高了, 待优化
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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];
        
        ListNode *res = merge2Lists(lists[0], lists[1]);
        for(int i = 2; i < lists.size(); i ++) {
            res = merge2Lists(res, lists[i]);
        }
        return res;
    }
};