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
class Solution{
public:
    int dfs(TreeNode *root, int preSum)
    {
        if(!root) 
        {
            return 0; // 3种情况：1. 根节点为空，返回0；2. 左子节点为空，当前为中间节点，返回0；3.右子节点为空，当前为中间节点，返回0
        }
        int sum = preSum*10 + root->val;
        if(!root->left && !root->right)
        {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
class Solution2 {
public:
    int sum = 0;
    int tmp = 0;
    void dfs(TreeNode *root)
    {
        if(!root) return;
        int bk = tmp;
        tmp = tmp*10 + root->val;
        if(!root->left && !root->right)
        {
            sum += tmp;
            //cout<<"Sum:"<<sum<<":tmp"<<tmp<<endl;
        }
        dfs(root->left);
        dfs(root->right);
        tmp = bk;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};