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
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * first = &dummy;
        ListNode * second = &dummy;
        for(int i = 0; i <= n;i++)
        {
            if(first)
            first = first->next;
        }
        while(first)
        {
            first = first->next;
            second = second->next;
        }
        if(second->next)
        {
            second->next = second->next->next;
        }
        return dummy.next;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p1 = &dummy;
        ListNode *p2 = &dummy;
        for(int i = 0; i <= n; i++) // p1 需要比 p2快 n+1步！
        {
            if(p1)
            {
                p1 = p1->next;
            }
        }
        while(p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p2->next)
        {
            p2->next = p2->next->next;
        }
        return dummy.next;
    }
};