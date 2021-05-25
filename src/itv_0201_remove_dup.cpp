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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> s;
        ListNode *p = head, *pre = nullptr;
        while(p)
        {
            if(s.find(p->val) == s.end())
            {
                s.insert(p->val);
                pre = p;
                p = p->next;
            }
            else
            {
                pre->next = p->next;
                p = p->next;
            }
        }
        return head;
    }
};