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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next) return nullptr;
        ListNode *p1 = head, *p2 = head;
        while(p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2)
            {
                ListNode *p3 = head;
                while(p3 != p1)
                {
                    p3 = p3->next;
                    p1 = p1->next;
                }
                return p3;
            }
        }
        return nullptr;
    }
};