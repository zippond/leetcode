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
        int carry = 0, x = 0, y = 0, sum = 0;
        ListNode dummy, *cur = &dummy;
        while(l1||l2||carry)
        {
            x = l1?l1->val:0;
            y = l2?l2->val:0;
            sum = x+y+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy.next;
    }
};