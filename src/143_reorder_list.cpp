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
        void reorderList2(ListNode* head) {
            if(!head||!head->next||!head->next->next) return;
            ListNode * pl = head;
            vector<ListNode *> s;
            while(pl)
            {
                s.push_back(pl);
                pl = pl->next;
            }
            pl = head;
            for(int i = 1, j = s.size()-1; i <= j; i++,j--)
            {
                pl->next = s[j];
                pl->next->next = s[i];
                pl = s[i];
            }
            pl->next = nullptr;
        }
        ListNode *getMid(ListNode *head)
        {
            ListNode *p1 = head, *p2 = head;
            //while(p2&&p2->next&&p2->next->next)
            while(p2&&p2->next)
            {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            return p1;
        }
        ListNode *reverseList(ListNode *head)
        {
            ListNode * pre = nullptr;
            ListNode * cur = head;
            while(cur)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            return pre;
        }
        void mergeLists(ListNode *l1, ListNode *l2)
        {
            ListNode* pl1 = l1, *pl2 = l2;
            while(pl1&&pl2)
            {
                pl1 = l1->next;
                pl2 = l2->next;

                l1->next = l2;
                l1 = pl1;

                l2->next = l1;
                l2 = pl2;
            }
        }
        void reorderList(ListNode *head)
        {
            if(!head||!head->next||!head->next->next) return;
            ListNode *mid = getMid(head);
            ListNode *l1 = head;
            ListNode *l2 = mid->next;
            mid->next = nullptr;
            l2 = reverseList(l2);
            mergeLists(l1, l2);
        }
    };