#include "data_structures/structures.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = NULL;
    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(root == p) return p;
        if(root == q) return q;
        if(left == p && right == q || left == q && right == p){
            res = root;
            return root;
        }
        if(left == p || left == q) return left;
        if(right == p || right == q) return right;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res1 = traverse(root, p, q);
        if(res) return res;
        return res1;
    }
};