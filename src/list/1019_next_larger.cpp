/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://blog.csdn.net/qq_21201267/article/details/103796861
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;//存储数值
        stack<int> idx;//存储下标
        int n = 0;
        for( ; head; head=head->next)
        {
        	while(!stk.empty() && stk.top() < head->val)//不单调递减, 更新栈内所有[比当前节点小]的NGE!
        	{
        		stk.pop();
        		ans[idx.top()] = head->val;//当前位置找到了比它大的最近的数
        		idx.pop();
        	}
        	stk.push(head->val);//数值
        	idx.push(n++);//下标
        	ans.push_back(0);//比当前数大的还未出现，先补0
        }
        return ans;
    }
};
