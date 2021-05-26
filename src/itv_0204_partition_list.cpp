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
    ListNode* partition(ListNode* head, int x) {
        ListNode sdummy(0), bdummy(0);
        ListNode *psmall = &sdummy, *pbig = &bdummy, *p = head;
        while(p)
        {
            if(p->val < x)
            {
                psmall->next = p;
                psmall = p;
            }
            else
            {
                pbig->next = p;
                pbig = p;
                
            }
            p = p->next;
        }
        psmall->next = bdummy.next;
        pbig->next = nullptr;   // 置空！
        return sdummy.next;
    }
};