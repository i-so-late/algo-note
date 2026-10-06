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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && subRoot) return false;
        queue<TreeNode*> mT;
        if(root) mT.push(root);
        while(!mT.empty()){
            TreeNode* tmp = mT.front();
            mT.pop();
            if(tmp->val == subRoot->val){
                if (isSameTree(tmp, subRoot)) return true;
            }
            if(tmp->left) mT.push(tmp->left);
            if(tmp->right) mT.push(tmp->right);
        }
        return false;
    }
};