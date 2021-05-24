/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node dummy;
        dummy.next = head;
        dummy.prev = dummy.child = nullptr;
        Node *pre = &dummy;
        Node *p = head;
        dfs(pre, head);
        head->prev = nullptr;
        return head;
    }
    Node *dfs(Node *pre, Node *root)
    {
        if(!root) return pre;
        pre->next = root;
        root->prev = pre;
        Node *next = root->next;
        Node *tail = dfs(root, root->child);
        root->child = nullptr;
        return dfs(tail, next);
    }
};