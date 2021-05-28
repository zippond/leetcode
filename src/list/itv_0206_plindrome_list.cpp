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
    ListNode *getMid(ListNode *head)
    {
        ListNode *p1 = head, *p2 = head;
        while(p2&&p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    ListNode *reverse(ListNode *head)
    {
        if(!head||!head->next) return head;
        ListNode *nhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nhead;
    }
    ListNode *reverse1(ListNode *head)
    {
        ListNode *pre = nullptr, *p = head;
        while(p)
        {
            ListNode *tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *mid = getMid(head);
        ListNode *nmid = reverse(mid);
        int i = 0;
        while(nmid)
        {
            if(nmid->val != head->val) return false;
            nmid = nmid->next;
            head = head->next;
        }
        return true;
    }
};