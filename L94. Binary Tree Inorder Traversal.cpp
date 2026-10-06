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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            if(st.top() != NULL){
                TreeNode* tmp = st.top();
                st.pop();
                if(tmp->right) st.push(tmp->right);
                st.push(tmp);
                st.push(nullptr);
                if(tmp->left) st.push(tmp->left);
            }else{
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};