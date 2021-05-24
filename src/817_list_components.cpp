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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        for(int i = 0; i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int count = 0;
        while(head)
        {
            if(s.count(head->val))
            {
                if((!head->next)||(!s.count(head->next->val)))
                {
                    count++;
                }
            }
            head = head->next;
        }
        return count;

    }
    int numComponents2(ListNode* head, vector<int>& nums) {
        if(!nums.size()) return 0;
        map<int, int> idx;
        ListNode *p = head;
        int pos = 0;
        while(p)
        {
            idx[p->val] = pos++;
            p = p->next;
        }
        vector<int> v;
        for(int i = 0; i< nums.size();i++)
        {
            v.push_back(idx[nums[i]]);
        }
        sort(v.begin(), v.end());
        int count = 1;
        for(int i = 1; i < v.size();i++)
        {
            if((v[i] - v[i-1]) > 1) count++;
        }
        return count;
    }
};