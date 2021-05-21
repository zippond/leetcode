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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode *p = root;
        while(p)
        {
            len++;
            p = p->next;
        }
        int minlen = len/k;
        int plen = minlen;
        int longparts = len%k;
        //cout<<"Len = "<<len<<" plen="<<plen<<" longparts="<<longparts<<endl;
        vector<ListNode *> v;
        ListNode dummy; 
        dummy.next = root;
        ListNode *pre = &dummy;
        for(int i = 0; i < k; i++)
        {
            if(!pre) 
            {
                v.push_back(nullptr);
                continue;
            }
            v.push_back(pre->next);
            ListNode *tmp = pre->next;
            pre->next = nullptr;
            pre = tmp;
            if( i < longparts)
            {
                plen = minlen + 1;
            }
            else
            {
                plen = minlen;
            }
            //cout<<"Pre="<<pre->val<<" plen="<<plen<<endl;
            for(int j = 0; j < plen-1; j++)
            {
                if(!pre) break;
                pre = pre->next;
            }
        }
        return v;
    }
};