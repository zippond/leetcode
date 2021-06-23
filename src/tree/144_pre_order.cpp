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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            ret.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return ret;
    }
};
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        dfs(root, ret);
        return ret;
    }
    void dfs(TreeNode *root, vector<int>& v)
    {
        if(!root) return;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
};