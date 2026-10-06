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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<double> res;
        if(root == NULL) return res;
        q1.push(root);
        while(!q1.empty() || !q2.empty()){
            double tmp=0;
            int cnt = 0;
            while(!q1.empty()){
                q2.push(q1.front());
                tmp += q1.front()->val;
                cnt++;
                q1.pop();
            }
            res.push_back(tmp/cnt);
            while(!q2.empty()){
                if(q2.front()->left) q1.push(q2.front()->left);
                if(q2.front()->right) q1.push(q2.front()->right);
                q2.pop();
            }
        }
        return res;
    }
};