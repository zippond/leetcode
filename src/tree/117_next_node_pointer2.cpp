/*
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/37879/Simple-C%2B%2B-Recursion-With-Comments
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *find_next_child(Node *root)
    {
        while(root)
        {
            if(root->left) return root->left;
            if(root->right) return root->right;
            root = root->next;
        }
        return nullptr;
    }
    Node* connect(Node* root) {
        if(!root) return nullptr;
        if(root->left)
        {
            if(root->right) 
            {
                root->left->next = root->right;
            }
            else
            {
                root->left->next = find_next_child(root->next);
            }
        }
        if(root->right)
        {
            root->right->next = find_next_child(root->next);
        }
        
        connect(root->right); // 先连后面的。保证链表的后段是连续的！
        connect(root->left);
        return root;
    }
};