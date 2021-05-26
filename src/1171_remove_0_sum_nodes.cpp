/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 前缀和问题！
 * https://www.jianshu.com/p/91b0a04dea0e
 */
class Solution {
public:
    // 单次扫描有问题！
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode *> m;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        int sum = 0;
        while(p)
        {
            sum += p->val;
            cout<<"Sum="<<sum<<endl;
            if(m.find(sum) != m.end())
            {
                m[sum] ->next = p->next;
            }
            else
            {
                m[sum] = p;
            }
            p = p->next;
        }
        return dummy.next;
    }
    ListNode* removeZeroSumSublists2(ListNode* head) {
        unordered_map<int, ListNode *> m;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        int sum = 0;
        while(p)
        {
            sum += p->val;
            m[sum] = p;
            p = p->next;
        }
        sum = 0;
        p = &dummy;
        while(p)
        {
            sum += p->val;
            p->next = m[sum]->next;
            p = p->next;
        }
        return dummy.next;
    }
    
};