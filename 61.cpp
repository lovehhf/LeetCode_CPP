
/* 61. 旋转链表
 * https://leetcode-cn.com/problems/rotate-list/
 *
 * 1. 找到尾节点, 记录链表长度
 * 2. 找到倒数第 k + 1 节点, 记为 p,
 * 3. 尾结点next指向头结点, 记录p的next指针为新的头结点, p 的 next 指针指向空
 * 4. 返回新的头结点
 *
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n = 1;  // 链表长度
        ListNode *tail = head;
        while(tail->next) {
            // 记录尾结点和链表长度
            tail = tail->next;
            n ++;
        }
        k = n - k % n;

        // 倒数第 k + 1 个节点是新的尾结点, 往前走 n - k - 1 步
        ListNode *p = head;
        while(-- k) p = p->next;


        tail->next = head;
        head = p->next;
        p->next = NULL;

        return head;
    }
};