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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != p2)
        {
            if(p1)
            {
                p1 = p1->next;
            }
            else
            {
                p1 = headB;
            }
            if(p2)
            {
                p2 = p2->next;
            }
            else
            {
                p2 = headA;
            }
        }
        return p1;
    }
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1||p2)
        {
            if(p1 == p2) return p1;
            if(!p1) 
            {
                p1 = headB;
            }
            else 
            {
                p1 = p1->next;
            }
            if(!p2) 
            {
                p2 = headA;
            }
            else 
            {
                p2 = p2->next;
            }
        }
        // 不相交，同时走到终点
        return nullptr;
    }
};