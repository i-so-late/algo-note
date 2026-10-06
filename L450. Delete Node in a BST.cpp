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
    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return NULL;
        TreeNode* cur = root, *prev = NULL;
        while(cur){
            if(key == cur->val) break;
            prev = cur;
            if(key>cur->val) cur = cur->right;
            else cur = cur->left;
        }
        if(!cur) return root;
        TreeNode* rightCur = cur->right, *rightPrev = cur;
        while(rightCur){
            if(rightCur->left){
                rightPrev = rightCur;
                rightCur = rightCur->left;
            }else break;
        }
        if(!prev){  //root is the key
            if(rightPrev == cur && !rightCur){ // key's right substree is NULL
                return cur->left;
            }else{
                if(rightPrev == cur){
                    rightCur->left = root->left;
                    return rightCur;
                }else{
                    rightPrev->left = rightCur->right;
                    rightCur->left = root->left;
                    rightCur->right = root->right;
                    return rightCur;
                }
            }
        }else{ // key is not on the root
            if(rightPrev == cur && !rightCur){ // key's right substree is NULL
                if(prev->left == cur){
                    prev->left = cur->left;
                }else{
                    prev->right = cur->left;
                }
            }else{
                if(rightPrev == cur){
                    rightCur->left = cur->left;
                    if(prev->left == cur){
                        prev->left = rightCur;
                    }else{
                        prev->right = rightCur;
                    }
                }else{
                    rightPrev->left = rightCur->right;
                    rightCur->left = cur->left;
                    rightCur->right = cur->right;
                    if(prev->left == cur){
                        prev->left = rightCur;
                    }else{
                        prev->right = rightCur;
                    }
                }          
            }
            return root;
        }
    }
};