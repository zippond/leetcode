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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p0 = list1, *p1, *p2;
        /*
        int i;
        for(i = 1, p1 = list1; (i < a)&&p1; i++)
        {
            p1 = p1->next;
        }
        for(i = 0, p2 = list1; (i < b)&&p2; i++)
        {
            p2 = p2->next;
        }
        */
        for(int i = 0; i< b; i++)
        {
            if(i == (a-1))
            {
                p1 = p0;
            }
            p0 = p0->next;
        }
        p2 = p0;
        ListNode *p3 = list2;
        while(p3->next)
        {
            p3 = p3->next;
        }
        p1->next = list2;
        p3->next = p2->next;
        return list1;
    }
};