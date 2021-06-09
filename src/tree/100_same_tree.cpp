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
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        stack<TreeNode *> sp, sq;
        while(p||!sp.empty())
        {
            //if((p == nullptr)^(q == nullptr)) return false; //
            while(p)
            {
                sp.push(p);
                if(q)
                {
                    if(p->val != q->val) // 1. 如果 值不同，不一样。
                    {
                        return false;
                    }
                    sq.push(q);
                    q = q->left;
                }
                else    // 2. 如果 q 为空，不一样
                {
                    return false;
                }
                p = p->left;

            } // p 左下到底
            if(q) // 3. 如果q不为空， 不一样。
            //if(q||(q&&q->left)) // 如果q 还有左子节点，不一样
            {
                return false;
            }

            TreeNode * pt = sp.top();
            TreeNode * qt = sq.top();
            sp.pop();
            sq.pop();
            if(pt->val != qt->val) return false; // 4. 重复，或者短路
            p = pt->right;
            q = qt->right;
            if((p == nullptr)^(q == nullptr)) return false;  // 5. 右子树不同
        }
        return sp.empty()&&sq.empty();
    }
};