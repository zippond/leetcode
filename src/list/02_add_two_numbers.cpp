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

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        int carry = 0;
        ListNode * head = l1;
        ListNode * cur = l1;
        while(l1)
        {
            cur = l1;
            int x = l1->val;
            int y = l2?l2->val:0;
            int sum = x + y + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2?l2->next:nullptr;
            //cout<<"cur"<<cur->val<<" carry "<<carry<<endl;
        }
        if(carry&& !l2)
        {
            cur->next = new ListNode(1);
            return head;
        }
        cur->next = l2;
        while(l2)
        {
            cur = l2;
            int y = l2->val;
            int sum = y + carry;
            l2->val = sum % 10;
            carry = sum / 10;
            l2 = l2->next;
        }
        if(carry)
        {
            cur->next = new ListNode(1);
        }
        return head;
    }
};