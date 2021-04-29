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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode * next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
    ListNode* swapPairsLoop(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode dummy;
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = dummy.next;
        ListNode *next = cur->next;
        while(cur&&next)
        {
            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = cur;
            cur = cur->next;
            next = cur?cur->next:nullptr;
        }
        return dummy.next;
    }
};