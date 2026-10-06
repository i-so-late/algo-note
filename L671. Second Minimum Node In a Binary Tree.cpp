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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int mini = root->val;
        long long mini2 = 2147483648;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; ++i){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->val > mini && tmp->val < mini2){
                    mini2 = tmp->val;
                }
                if(tmp->left){
                    q.push(tmp->left); q.push(tmp->right);
                }
            }
            
        }
        if(mini2 != 2147483648) return mini2;
        return -1;
    }
};