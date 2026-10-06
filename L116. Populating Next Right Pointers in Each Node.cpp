#include "data_structures/structures.hpp"

/*
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
    Node* connect(Node* root) {
        queue<Node*> q1;
        if(root == NULL) return root;
        q1.push(root);
        while(!q1.empty()){
            int cnt = q1.size();
            for(size_t i =0; i<cnt; ++i){
                Node* tmp = q1.front();
                q1.pop();
                if(tmp->left) q1.push(tmp->left);
                if(tmp->right) q1.push(tmp->right);
                if(i<cnt-1)
                    tmp->next = q1.front();
            }
        }
        return root;
    }
};