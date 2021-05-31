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
        if(s>e) return {nullptr};
        vector<TreeNode*> left, right;
        for(int i = s; i <= e; i++ )
        {
            left = generateTrees(s, i-1);
            right = generateTrees(i+1, e);
            for(auto l:left)
            {
                cout<<"Loop L"<<endl;
                for(auto r: right)
                {
                    cout<<"Loop R"<<endl;
                    cout<<"i="<<i<<endl;
                    TreeNode *n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    ret.push_back(n);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return generateTrees(1, n);
    }
};