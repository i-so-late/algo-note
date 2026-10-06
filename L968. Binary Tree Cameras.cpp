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
        if(!root->left && !root->right){
            return 0;
        }
        int left = -1;
        if(root->left){
            left = traverse(root->left);
        }
        int right = -1;
        if(root->right){
            right = traverse(root->right);
        }
        if(left == 0 || right == 0){
            res++;
            return 1;
        }
        else if(left == 1 || right == 1){
            return 2;
        }else{
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(traverse(root)==0)
            ++res;
        return res;
    }
};