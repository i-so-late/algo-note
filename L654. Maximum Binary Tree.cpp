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
    TreeNode* traverse(vector<int>& nums, int begin, int end){
        if(begin >= end) return NULL;
        pair<int, int> p(-1,-1);
        for(int i=begin; i<end; ++i){
            if(nums[i]>p.first){
                p.first = nums[i];
                p.second = i;
            }
        }
        TreeNode* root = new TreeNode(p.first);
        root->left = traverse(nums, begin, p.second);
        root->right = traverse(nums, p.second+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums, 0, nums.size());
    }
};