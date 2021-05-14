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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode *pre = &dummy;
        while(pre->next)
        {
            if(pre->next->val == val)
            {
                pre->next = pre->next->next;
            }
            else
            {
                pre = pre->next;
            }
        }
        return dummy.next;

    }
};