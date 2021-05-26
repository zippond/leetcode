/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> m;
        for(Node *p = head;p; p = p->next)
        {
            m[p] = new Node(p->val);
        }
        for(Node *p = head; p; p=p->next)
        {
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
        }
        return m[head];
    }
};