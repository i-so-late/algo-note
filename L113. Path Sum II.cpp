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
    vector<vector<int>> res;
    void traverse(TreeNode* root, int sum, vector<int>& rec){
        if(!root) return ;
        sum += root->val;
        rec.push_back(root->val);
        if(sum == target && !root->left && !root->right){
            res.push_back(rec);
            rec.pop_back();
            return;
        }
        traverse(root->left, sum, rec);
        traverse(root->right, sum, rec);
        rec.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        if(!root) return res;
        vector<int> rec;
        traverse(root, 0, rec);
        return res;
    }
};