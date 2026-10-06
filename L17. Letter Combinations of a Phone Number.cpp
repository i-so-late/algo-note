#include "data_structures/structures.hpp"

class Solution {
public:
    vector<string> dic{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void backTrack(string digits, int start, string& path){
        //cout<< digits.size()<<endl;
        if(start == digits.size()){
            res.push_back(path);
            return;
        }
        int idx = digits[start]-'2';
        ++start;
        for(int i=0;i<dic[idx].size(); ++i){
            path += dic[idx][i];
            backTrack(digits, start, path);
            path.resize(path.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        string path = "";
        backTrack(digits, 0, path);
        return res;
    }
};