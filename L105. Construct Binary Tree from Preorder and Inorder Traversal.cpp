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
    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, int inBegin, int inEnd, int preBegin, int preEnd){
        if(preEnd <= preBegin) return NULL;
        int val = preorder[preBegin];
        TreeNode* root = new TreeNode(val);
        preBegin += 1;

        int inorderMid = 0;
        for(int i=inBegin; i<inEnd; i++){
            if(inorder[i] == val) inorderMid = i;
        }
        //int leftLength = inorderMid - inBegin;
        root->left = traverse(preorder, inorder, inBegin, inorderMid, preBegin, preBegin+inorderMid-inBegin);
        root->right = traverse(preorder, inorder, inorderMid+1, inEnd, preBegin+inorderMid-inBegin, preEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traverse(preorder, inorder, 0, inorder.size(), 0, preorder.size());
    }
};