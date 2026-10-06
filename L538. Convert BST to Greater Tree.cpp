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
    int prev = 0;
    void traverse(TreeNode* root){
        if(!root) return ;
        traverse(root->right);
        prev += root->val; 
        root->val = prev;
        traverse(root->left);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};