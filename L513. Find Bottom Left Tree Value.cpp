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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int res = 0;
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                TreeNode* tmp = q1.front();
                q1.pop();
                q2.push(tmp);
            }
            res = q2.front()->val;
            while(!q2.empty()){
                TreeNode* tmp = q2.front();
                q2.pop();
                if(tmp->left) q1.push(tmp->left);
                if(tmp->right) q1.push(tmp->right);
            }
        }
        return res;
    }
};