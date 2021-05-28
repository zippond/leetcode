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
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(-128);
        ListNode bigDummy(128);
        ListNode *ps = &smallDummy;
        ListNode *pb = &bigDummy;
        ListNode *p = head;
        while(p)
        {
            if(p->val < x)
            {
                ps->next = p;
                ps = ps->next;
            }
            else
            {
                pb->next = p;
                pb = pb->next;
            }
            p = p->next;
        }
        ps->next = bigDummy.next;
        pb->next = nullptr; // !!!!!
        return smallDummy.next;
    }
};
