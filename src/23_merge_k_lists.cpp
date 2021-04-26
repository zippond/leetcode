/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists2(vector<ListNode *> &lists)
    {
        if(lists.size() == 0) return nullptr;
        return mergeKlistsLoop(lists);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.size() == 0) return nullptr;
        mergeKListsRec(lists, 0, lists.size());
        return lists[0];
    }

    ListNode * mergeKListsRec(vector<ListNode *> &lists, int start, int end)
    {
        if((end - start) == 1) { return lists[start];}
        int mid = start + (end - start)/2;
        ListNode * l = mergeKListsRec(lists, start, mid);
        ListNode * r = mergeKListsRec(lists, mid, end);
        return merge2Lists(l, r);
    }
    ListNode * mergeKlistsLoop(vector<ListNode *> &lists)
    {
        int len = 1;
        int size = lists.size();
        while(len < size)
        {
            for(int i = 0; (i + len)< size; i += 2* len)
            {
                lists[i] = merge2Lists(lists[i], lists[i+len]);
            }
            len *= 2;
        }
        return lists[0];
    }

    ListNode *merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(0);
        ListNode * cur = &dummy;
        while(l1&&l2)
        {
            if((l1->val) < (l2->val))
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy.next;
    }
    
};