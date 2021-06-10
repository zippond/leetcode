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
    bool isSymmetric(TreeNode* root) {
        return help(root, root);
    }
    bool help(TreeNode *left, TreeNode *right)
    {
        if(!left && !right)
        {
            return true;
        }
        if(!left || !right)
        {
            return false;
        }
        if(left->val != right->val)
        {
            return false;
        }
        return help(left->left, right->right)&&help(left->right, right->left);
    }
};