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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *getMid(ListNode *head, ListNode *tail)
    {
        ListNode *slow = head, *fast = head;
        while(fast&&fast->next)
        {
            if((fast == tail)||(fast->next == tail))
            {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode *buildTree(ListNode *head, ListNode *tail)
    {
        if(head == tail) return nullptr;
        ListNode *mid = getMid(head, tail);
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildTree(head, mid);
        root->right = buildTree(mid->next, tail);
        return root;
    }
    TreeNode *sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};