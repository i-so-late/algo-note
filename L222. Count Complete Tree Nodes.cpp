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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftdep = 0, rightdep = 0;
        while(left){
            leftdep++;
            left = left->left;
        }
        while(right){
            rightdep++;
            right = right->right;
        }
        if(leftdep == rightdep){
            return (2<<leftdep)-1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};