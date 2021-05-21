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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *pfast = head, *pslow = head, *p1;
        for(int i = 1; i < k; i++)
        {
            pfast = pfast->next;
        }
        p1 = pfast;
        while(pfast->next)
        {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        //cout<<"p1:"<<p1->val<<" pslow:"<<pslow->val<<endl;
        if(p1 == pslow) return head;
        int tmp = p1->val;
        p1->val = pslow->val;
        pslow->val = tmp;
        return head;
    }
};