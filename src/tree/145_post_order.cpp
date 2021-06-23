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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        stack<pair<TreeNode *, bool>> s;
        pair<TreeNode *, bool> r(root, false);
        s.push(r);
        while(!s.empty())
        {
            pair<TreeNode *, bool> &p = s.top();
            TreeNode *node = p.first;
            if(p.second)
            {
                s.pop();
                v.push_back(node->val);
                continue;
            }
            p.second = true;
            if(node->right)
            {
                pair<TreeNode *, bool> r(node->right, false);
                s.push(r);
            }
            if(node->left)
            {
                pair<TreeNode *, bool> l(node->left, false);
                s.push(l);
            }

        }
        return v;
    }
};
class Solution2 {
public:
    void dfs(TreeNode * root, vector<int>& v)
    {
        if(!root) return;
        dfs(root->left, v);
        dfs(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        dfs(root, v);
        return v;
    }
};