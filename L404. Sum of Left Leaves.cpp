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
    int traverse(TreeNode* root, bool isLeft){
        if(!root->left && !root->right){
            if(isLeft) return root->val;
            return 0;
        }
        int res=0;
        if(root->left) res += traverse(root->left, true);
        if(root->right) res += traverse(root->right, false);
        return res; 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return traverse(root, false);
    }
};