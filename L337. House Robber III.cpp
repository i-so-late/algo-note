#include <data_structures/structures>
using namespace std;


class Solution {
public:
    pair<int, int> traverse(TreeNode* root){
        pair<int, int> tmp;
        if(!root->left && !root->right){
            tmp.first = 0;
            tmp.second = root->val;
            return tmp;
        }
        pair<int, int> left;
        pair<int, int> right;
        if(root->left)
            left = traverse(root->left);
        if(root->right)
            right = traverse(root->right);
        if(!root->left){
            pair<int, int> res;
            res.first = max(right.first, right.second);
            res.second = right.first + root->val;
            return res;
        }
        if(!root->right){
            pair<int, int> res;
            res.first = max(left.first, left.second);
            res.second = left.first + root->val;
            return res;
        }
        pair<int, int> res;
        res.first = max(left.second+right.second, left.second+right.first);
        res.first = max(res.first, left.first+right.second);
        res.first = max(res.first, left.first + right.first);
        res.second = left.first + right.first+root->val;
        return res;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        auto tmp = traverse(root);
        return max(tmp.first, tmp.second);
    }
};