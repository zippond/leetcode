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
    vector<TreeNode *> v;
    void preOrder(TreeNode *root)
    {
        stack<TreeNode *> s;
        if(root) s.push(root);
        while(!s.empty())
        {
            TreeNode * node = s.top();
            v.push_back(node);
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        preOrder(root);
        for(int i = 0; i < v.size() - 1; i++)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i+1];
        }
        //if(v.size()) v[v.size()-1]->left = nullptr; // 最后一个肯定是叶节点！
    }

};