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
    unordered_map<int, int> pos;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size();i++)
        {
            pos[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode * helper(vector<int>& preorder, int prestart, int preend, 
    vector<int>& inorder,int instart,int inend)
    {
        if(prestart > preend) // 左闭右闭, start > end时为空
        {
            return nullptr;
        }
        TreeNode * root = new TreeNode(preorder[prestart]);
        // 获取中序的idx
        int in_idx = pos[preorder[prestart]];
        //int llen = in_idx - instart;
        //int rlen = inend - in_idx;
        root->left = helper(preorder, prestart + 1, prestart + in_idx - instart, 
        inorder, instart, in_idx -1);
        //root->right = helper(preorder, prestart + llen + 1, prestart + llen + 1 + rlen,
        root->right = helper(preorder, prestart + in_idx - instart + 1, preend,
        inorder, in_idx + 1, inend);
        return root;
    }
};