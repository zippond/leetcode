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
        Node *p = head;
        unordered_map<Node*, Node*> m;
        // 第一步，创建所有节点
        while(p)
        {
            m[p] = new Node(p->val);
            p = p->next;
        }

        // 第二步，更新节点链接，包括next 和 random
        p = head;
        while(p)
        {
            m[p]->next = m[p->next];
            m[p]->random = p->random?m[p->random]:nullptr;
            p = p->next;
        }
        return m[head];
    }
};