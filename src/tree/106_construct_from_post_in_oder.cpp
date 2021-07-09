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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            pos[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode * helper(vector<int>& in, int istart, int iend, vector<int>& p, int pstart, int pend)
    {
        if(pstart > pend) return nullptr;
        int rootval = p[pend];
        TreeNode * root = new TreeNode(rootval);
        int in_pos = pos[rootval];
        int left_size = in_pos - istart;
        int right_size = iend - in_pos;
        root->left = helper(in, istart, istart + left_size - 1, p, pstart, pstart + left_size -1);
        root->right = helper(in, in_pos + 1, iend, p, pstart + left_size, pend-1);
        return root;
    }
};