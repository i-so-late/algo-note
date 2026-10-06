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
    vector<string> res;
    void traverse(TreeNode* root, string s){
        if(!root) return;
        s += to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(s);
            return;
        }
        s += "->";
        traverse(root->left,s);
        traverse(root->right, s);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        traverse(root, s);
        return res;
    }
};