


/** 
 * 2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        // t存储各位的和, carry为进位标记
        int t = 0, carry = 0;
        while(l1 || l2 || carry)
        {
            t = carry;
            if(l1)
            {
                t += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                t += l2->val;
                l2 = l2->next;
            }
            carry = t/10;
            t %= 10;
            p->next = new ListNode(t);
            p = p->next;
        }
        return dummy.next;
    }
};