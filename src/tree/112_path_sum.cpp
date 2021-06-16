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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false; // 父节点只有一个子节点，当前路径走到尽头，直接返回false
        if(!root->left && !root->right) return targetSum == root->val; // 终止条件: 到达叶节点
        int newSum = targetSum - root->val;
        return hasPathSum(root->left, newSum)||hasPathSum(root->right, newSum);
    }
};