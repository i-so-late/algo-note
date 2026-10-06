#include "data_structures/structures.hpp"

class Solution {
public:
    vector<string> res;
    void backTrack(string s, int l, int r){
        if(l==0 && r==0){
            res.emplace_back(s);
            return;
        }
        if(l>0) backTrack(s+"(", l-1, r);
        if(r>l) backTrack(s+")", l, r-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s ="";
        backTrack(s, n, n);
        return res;
    }
};