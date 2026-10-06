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
    vector<int> findMode(TreeNode* root) {
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

        int prev = rec[0];
        int m = 1;
        int prevIdx = 0;
        for(int i=1; i<rec.size(); ++i){
            if(rec[i] != prev){
                int gap = i - prevIdx;
                if(gap > m) m = gap;
                prev = rec[i];
                prevIdx = i;
            }
        }
        if(rec.size() - prevIdx > m) m = rec.size()-prevIdx;
        vector<int> res;
        prev = rec[0];
        prevIdx = 0;
        for(int i=1; i<rec.size(); ++i){
            if(rec[i] != prev){
                if(i-prevIdx == m){
                    res.push_back(prev);
                }
                prev = rec[i];
                prevIdx = i;
            }
        }
        if(rec.size()-prevIdx == m) res.push_back(prev);
        return res;
    }
};