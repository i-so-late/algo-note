#include "data_structures/structures.hpp"

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int dep = 0;
        if(root ==nullptr) return dep;
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            dep++;
            while(!q2.empty()){
                if(q2.front()->left) q1.push(q2.front()->left);
                if(q2.front()->right) q1.push(q2.front()->right);
                if(q2.front()->left==NULL && q2.front()->right==NULL) return dep;
                q2.pop();
            }
        }
        return dep;
    }
};