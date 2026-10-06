#include "data_structures/structures.hpp"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int traverse(Node* root, int dep){
        if(!root) return dep;
        int m = dep+1;
        for(auto p: root->children){
            m = max(m, traverse(p, dep+1));
        }
        return m;
    }
    int maxDepth(Node* root) {
        return traverse(root, 0);
    }
};