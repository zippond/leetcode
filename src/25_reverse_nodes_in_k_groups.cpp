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
            // save
            next = a->next;
            // update
            a->next = pre;
            // reset
            pre = a;
            a = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode dummy;
        ListNode * tail = &dummy;
        ListNode * p1 = head;
        ListNode * p2 = head;
        bool reverseLast = false;

        while(p2)
        {          
            int i = 0;
            for(i = 0; i < k; i++)
            {
                p2 = p2->next;
                if(!p2) 
                {
                    if(i == (k-1))
                    {
                        reverseLast = true;
                    }
                    break;
                }
                
            }
            if(p2||(reverseLast))
            {
                tail->next = reverse(p1, p2);
            }
            else{
                tail->next = p1;
            }
            tail = p1;
            p1 = p2;
        }
        return dummy.next;
    }
    ListNode* reverseKGroupRec(ListNode* head, int k) {
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