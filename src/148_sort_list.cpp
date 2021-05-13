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
    ListNode * getMid(ListNode * head, ListNode * tail)
    {
        ListNode *p1 = head, *p2 = head;
        while(p2 && p2->next)
        {
            if(p2 == tail || p2->next == tail)
            {
                break;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    ListNode *merge(ListNode *l, ListNode *r)
    {
        ListNode dummy;
        ListNode *p = &dummy;
        while(l&&r)
        {
            if(l->val < r->val)
            {
                p->next = l;
                l = l->next;
            }
            else
            {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        if(l) p->next = l;
        else p->next = r;
        return dummy.next;
    }
    ListNode *sort(ListNode *head, ListNode *tail) /* 左闭右开 */
    {
        if(head->next == tail) 
        {
            head->next = nullptr; // 断开！！！
            return head;
        }
        ListNode *mid = getMid(head, tail);
        ListNode *l = sort(head, mid);
        ListNode *r = sort(mid, tail);
        ListNode *nhead = merge(l, r);
        return nhead;
    }
    ListNode * sortList(ListNode* head) {
        if(!head || !head->next) return head;
        return sort(head, nullptr);
    }
};