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
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> v;
        stack<TreeNode *> s;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            TreeNode * node = s.top();
            v.push_back(node);
            s.pop();
            root = node->right;
        }
        TreeNode * p1 = nullptr, *p2 = nullptr;
        for(int i = 0; i < (v.size() - 1); i++)
        {
            if(v[i]->val > v[i+1]->val)
            {
                if(p1)
                {
                    p2 = v[i+1];
                }
                else
                {
                    p1 = v[i];
                    p2 = v[i+1];
                }
            }
        }
        if(!p1) return;
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};