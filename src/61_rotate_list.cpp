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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        if(!k) return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        int len = 0;
        while(p2){
            len++;
            p2 = p2->next;
        }
        int realk = k%len;
        if(realk == 0) return head;
        p2 = head;
        for(int i = 0; i < realk;i++)
        {
            p2 = p2->next;
        }
        while(p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *newhead = p1->next;
        p1->next = nullptr;
        p2->next = head;
        return newhead;
    }
};
