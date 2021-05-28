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
    vector<int> reversePrint(ListNode* head) {
        ListNode *p = head;
        vector<int> v;
        int count = 0;
        while(p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        int m = v.size()/2;
        for(int i = 0, j = v.size()-1; i < j; i++, j--)
        {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
        return v;
    }
};