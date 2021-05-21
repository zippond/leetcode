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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *p = nullptr;
        int carry = 0;
        while(s1.size()||s2.size()||carry)
        {
            int x = s1.size()?s1.top():0;
            int y = s2.size()?s2.top():0;
            int sum = x+y+carry;
            carry = sum/10;
            ListNode *n = new ListNode(sum%10, p);
            p = n;
            if(s1.size()) s1.pop();
            if(s2.size()) s2.pop();
        }
        return p;
    }
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        stack<ListNode *> s1, s2;
        ListNode *p = l1;
        while(p)
        {
            s1.push(p);
            p = p->next;
        }
        p = l2;
        while(p)
        {
            s2.push(p);
            p = p->next;
        }
        int carry = 0;
        p = nullptr;
        while(s1.size()||s2.size()||carry)
        {
            int x = s1.size()?s1.top()->val:0;
            int y = s2.size()?s2.top()->val:0;
            int sum = x + y + carry;
            carry = sum/10;
            ListNode * node = new ListNode(sum%10, p);
            p = node;
            if(s1.size()) s1.pop();
            if(s2.size()) s2.pop();
        }
        return p;
    }
};