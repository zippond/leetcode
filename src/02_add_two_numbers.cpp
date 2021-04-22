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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode * cur = &dummy;
        while(carry||l1||l2)
        {
            int x = l1?l1->val:0;
            int y = l2?l2->val:0;
            int sum = x + y + carry;
            carry = sum/10;

            cur->next = new ListNode(sum % 10);

            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
            cur = cur->next;
        }
        return dummy.next;
    }
};
