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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        ListNode *oh = head, *eh = head->next;
        ListNode *op = oh, *ep = eh;
        while(ep&&ep->next) // 共有偶数节点时，ep->next为空，停止；共有奇数节点时，ep在上一轮时被指为空 (op->next == nullptr)，停止
        {
            op->next = ep->next;
            op = op->next;
            ep->next = op->next;
            ep = ep->next;
        }
        op->next = eh;
        return oh;
    }
};