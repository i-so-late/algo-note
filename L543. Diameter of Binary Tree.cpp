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
    int res = 0;
    int traverse(TreeNode* root){
        if(!root) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        res = max(res, left + right);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return res;
        traverse(root);
        return res;
    }
};