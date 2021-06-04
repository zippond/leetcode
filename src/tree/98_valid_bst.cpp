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
    bool isValidBST2(TreeNode* root) {
        double pre = (double) INT_MIN - 1;
        stack<TreeNode *> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode *node = s.top();
            if(node->val <= pre) return false;
            s.pop();
            root = node->right;
            pre = node->val;
        }
        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    bool dfs(TreeNode *root, long long min, long long max)
    {
        if(!root) return true;
        if(root->val >= max) return false;
        if(root->val <= min) return false;
        return dfs(root->left, min, root->val)&&dfs(root->right, root->val, max);
    }
};