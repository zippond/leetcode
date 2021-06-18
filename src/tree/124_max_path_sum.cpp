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

// 理解错误，目标路径和是从任意节点开始的，不是根节点！
class Solution2 {
public:
    int maxSum = INT_MIN;
    int curSum = 0;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    void dfs(TreeNode *root)
    {
        if(!root) return;
        curSum += root->val;
        if(!root->left && !root->right)
        {
            if(curSum > maxSum)
            maxSum = curSum;
        }
        dfs(root->left);
        dfs(root->right);
        curSum -= root->val;
    }
};

class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int d = maxGain(root);
        return maxSum;
    }
    int maxGain(TreeNode *root) // 最大贡献值
    {
        if(!root) return 0;
        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};