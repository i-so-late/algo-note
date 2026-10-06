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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> rec;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                rec.push_back(root->val);
                root = root->right;
            }
        }
        int ab = INT_MAX;
        for(int i=1; i<rec.size(); ++i){
            ab = min(ab, rec[i]-rec[i-1]);
        } 
        return ab;
    }
};