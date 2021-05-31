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
    vector<TreeNode*> generateTrees(int s, int e) {
        vector<TreeNode *> ret;
        if(s>e) return {nullptr};   // 注意，返回包含空节点的数组！
        vector<TreeNode*> left, right;
        for(int i = s; i <= e; i++ )
        {
            left = generateTrees(s, i-1);
            right = generateTrees(i+1, e);
            for(auto l:left)
            {
                for(auto r: right)
                {
                    TreeNode *n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    ret.push_back(n);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees2(int n) {
        if(!n) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int n)
    {
        vector<vector<vector<TreeNode *>> dp(n+1, vector<vector<TreeNode*>>(n+1));
        for(int i = 1; i <= n; i++)
        {
            dp[i][i].push_back(new TreeNode(i));
            dp[i][i-1].push_back(nullptr);
        } 
        for(int i = n-1; i > 0; i--)
        {
            for(int j = i+1;j<=n;j++)
            {
                //
                vector<TreeNode *> v;
                for(int k = i; k <= j; k++)
                {
                    vector<TreeNode *> left = dp[i][k-1];
                    vector<TreeNode *> right = dp[k+1][j];
                    for(auto l: left )
                    {
                        for(auto r: right)
                        {
                            TreeNode * node = new TreeNode(k);
                            node->left = l;
                            node->right = r;
                            v.pus_back(node);
                        }
                    }
                }
                dp[i][j] = v;
            }
        }
        return dp[1][n];
    }
};