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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;
        while(cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode *reverseList2(ListNode *head)
    {
        if(!head||!head->next) return head;
        ListNode * newhead = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    ListNode *getMid(ListNode *head)
    {
        ListNode *p1 = head, *p2 = head;
        while(p2&&p2->next)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *mid = getMid(head);
        ListNode *secondHalf = reverseList2(mid);
        while(secondHalf)
        {
            if(head->val == secondHalf->val)
            {
                head = head->next;
                secondHalf = secondHalf->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};