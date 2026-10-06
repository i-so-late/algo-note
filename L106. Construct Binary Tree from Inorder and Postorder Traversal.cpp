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
    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd){
        if(postEnd <= postBegin) return NULL;
        int val = postorder[postEnd-1];
        TreeNode* root = new TreeNode(val);
        postEnd -= 1;

        int inorderMid = 0;
        for(int i=inBegin; i<inEnd; i++){
            if(inorder[i] == val) inorderMid = i;
        }
        //int leftLength = inorderMid - inBegin;
        root->left = traverse(inorder, postorder, inBegin, inorderMid, postBegin, postBegin+inorderMid-inBegin);
        root->right = traverse(inorder, postorder, inorderMid+1, inEnd, postBegin+inorderMid-inBegin, postEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traverse(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};