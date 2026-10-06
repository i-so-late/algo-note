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
    bool res=true;
    int traverse(TreeNode* root){
        if(!root) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        if(abs(left-right)>1) res = false;
        return max(left, right)+1; 
    }
    bool isBalanced(TreeNode* root) {
        traverse(root);
        return res;
    }
};