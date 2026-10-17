#include "data_structures/structures.hpp"


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


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        for(Node* p = head; p; p = p->next->next){
            Node* pnext = p->next;
            p->next = new Node(p->val);
            p->next->next = pnext;
        }
        for(Node* p = head; p; p = p->next->next){
            p->next->random = p->random? p->random->next : nullptr;
        }
        Node* root = head->next;
        Node* cur = root;
        for(Node* p = head; p; p=p->next){
            cur = p->next;
            p->next = p->next->next;
            cur->next = cur->next? cur->next->next : nullptr;
        }
        return root;
    }
};