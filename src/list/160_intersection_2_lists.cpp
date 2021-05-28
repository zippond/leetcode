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
        while(p1 != p2) // 当p1=p2时，若相交，则都在交点上，否则都在终点(nullptr)
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
};