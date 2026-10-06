#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool isPalindrome(string s, int start, int i){
        while(start<i){
            if(s[start]!=s[i]) return false;
            start++;
            i--;
        }
        return true;
    }
    void backTrack(string s, int start){
        if(start >= s.size()){
            res.push_back(path);
            return;
        }
        for(int i=start; i<s.size(); ++i){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                backTrack(s,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backTrack(s,0);
        return res;
    }
};