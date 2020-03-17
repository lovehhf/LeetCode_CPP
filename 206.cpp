
/* 206. 反转链表
 * https://leetcode-cn.com/problems/reverse-linked-list/
 *
 *  递归写法
 * eg: 1->2->3->NULL
 *  第一次递归: 1-> 2<-3 返回3， head = 2
 *  第二次:    NULL <- 1 <- 2 <- 3, 返回 3, head = 1
 */


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        //  翻转之后的链表头结点
        ListNode *p = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return p;
    }
};