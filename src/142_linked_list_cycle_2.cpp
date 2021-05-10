/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 1. p1 p2初次相遇时，p1 刚好跑了 n*(cycle_len)的长度
 * 2. p1 继续跑到环入口时，跑了 n*(cycle_len) + (pre_cycle)的长度. 若p1 继续跑之前，p3 指向头节点，则p3跑到环入口时，跑了pre_cycle步。此时p1 == p3.
 * 
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