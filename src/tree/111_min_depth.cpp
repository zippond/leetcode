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
    int minDepth2(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right) + 1;
        if(!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        queue<TreeNode *> q;
        q.push(root);
        int dep = 0;
        while(!q.empty())
        {
            dep++;
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(!node->left && !node->right) return dep;
                q.pop();
            }
        }
        return dep;
    }
};