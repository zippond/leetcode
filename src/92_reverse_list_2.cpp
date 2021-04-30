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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;
        ListNode * rpre = &dummy;
        for(int i = 0; i < (left - 1); i++)
        {
            rpre = rpre->next;
        }
        ListNode *rstart = rpre->next;

        ListNode *cur = rpre ->next;
        ListNode *nxt = cur ->next;
        ListNode *tmp;
        for(int i = left;i < right;i++)
        {
            tmp = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = tmp;
        }
        rpre->next = cur;
        rstart->next = nxt;
        return dummy.next;
    }
};