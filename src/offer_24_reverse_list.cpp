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
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = nullptr;
        ListNode * onext = head;
        ListNode * t = nullptr;
        while(onext)
        {
            t = onext->next;
            onext->next = cur;
            cur = onext;
            onext = t;
        }
        return cur;

    }
};