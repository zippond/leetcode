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
    bool isSubPath2(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(root->val == head->val)
        {
            return isSubPath(head->next, root->left) || isSubPath(head->next, root->right);
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right); // 这个相当于存在某条路径，该路径上依次包含list 子序列即可。子串中可包含其他节点。
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if(!head) return true;
        if(!root) return false;
        return dfs(head, root)||isSubPath(head, root->left)||isSubPath(head, root->right);
    }
    bool dfs(ListNode *head, TreeNode *root) // 找连续的！
    {
        if(!head) return true;
        if(!root) return false;
        if(head->val != root->val) return false;
        return dfs(head->next, root->left)||dfs(head->next, root->right);
    }
};