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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q1;
        queue<Node*> q2;
        vector<vector<int>> res;
        if(root == NULL) return res;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            vector<int> tmp;
            while(!q1.empty()){
                q2.push(q1.front());
                tmp.push_back(q1.front()->val);
                q1.pop();
            }
            res.push_back(tmp);
            while(!q2.empty()){
                for(auto nd: q2.front()->children){
                    q1.push(nd);
                }
                q2.pop();
            }
        }
        return res;
    }
};