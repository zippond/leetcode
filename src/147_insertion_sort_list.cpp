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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode dummy(INT_MIN, head);
        ListNode *tmppre = &dummy, *lastSorted = head, *cur = head->next;
        while(cur)
        {
            if(cur->val >= lastSorted->val)
            {
                lastSorted = cur;
                cur = cur->next;
            }
            else
            {
                tmppre = &dummy;
                while(tmppre->next->val < cur->val)
                {
                    tmppre = tmppre->next;
                }
                lastSorted->next = cur->next;
                cur->next = tmppre->next;
                tmppre->next = cur;
                cur = lastSorted->next;
            }
        }
        return dummy.next;
    }
};