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
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
    void dfs(TreeNode *root, int targetSum)
    {
        if(!root) return;
        targetSum -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(targetSum == 0)
            {
                result.push_back(path);
            }
            // fast path return. Small performance enhancement
            path.pop_back();
            return;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
};