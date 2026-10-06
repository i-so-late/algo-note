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
    int target;
    bool traverse(TreeNode* root, int sum){
        if(!root) return false;
        sum += root->val;
        if(sum == target && !root->left && !root->right) return true;
        return traverse(root->left, sum) || traverse(root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return traverse(root, 0);
    }
};