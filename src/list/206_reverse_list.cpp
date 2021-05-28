/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * p = head->next;
        ListNode * newhead = reverseList(head->next);
        p->next = head;
        head->next = nullptr;
        return newhead;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while(cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};