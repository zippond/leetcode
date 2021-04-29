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
    ListNode* reverse(ListNode *a, ListNode *b)
    {
        ListNode * pre = nullptr;
        ListNode * next;
        while(a != b)
        {
            next = a->next;
            a->next = pre;
            pre = a;
            a = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        for(int i = 0; i < k; i++)
        {
            if(!p2) return head;
            p2 = p2->next;
        }
        ListNode * newhead = reverse(p1, p2);
        p1->next = reverseKGroup(p2, k);
        return newhead;
    }
};