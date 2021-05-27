/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 82, 83区别：如果保留第一个重复的，则头节点不会变，不需要dummy；否则，头节点会变，需创建dummy，并且需要pre节点跳过所有重复的。
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(128);
        dummy.next = head;
        ListNode * pre = &dummy;
        ListNode * cur = head;
        while(cur)
        {
            if(cur->next&&(cur->val == cur->next->val))
            {
                int x = cur->val;
                while(cur&&(cur->val == x))
                {
                    cur = cur->next;
                }
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
