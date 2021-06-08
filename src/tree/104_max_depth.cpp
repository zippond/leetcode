#include <stack>
class Solution {
public:
    int maxDepth2(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        int dep = 0;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while(!s1.empty()||!s2.empty())
        {
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    TreeNode *node = s1.top();
                    s1.pop();
                    if(node->left) s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
                dep++;
            }
            else
            {
                while(!s2.empty())
                {
                    TreeNode *node = s2.top();
                    s2.pop();
                    if(node->left) s1.push(node->left);
                    if(node->right) s1.push(node->right);
                }
                dep++;                
            }
        }
        return dep;
    }
};