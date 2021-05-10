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
    void reorderList(ListNode* head) {
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
};