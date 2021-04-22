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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
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
};