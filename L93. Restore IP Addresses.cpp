#include "data_structures/structures.hpp"

class Solution {
public:
    vector<string> res;
    string path="";
    void backTrack(string s, int start, int part){
        if(part == 5){
            if(s.size() == start){
                res.push_back(path);
                return;
            }else return;
        } 
        string tmp = "";
        for(int i=start; i<start+3&&i<s.size(); ++i){
            if(i!=start && s[start]=='0') break;
            tmp += s[i];
            if((4-part)*3<s.size()-i-1) continue;
            if(stoi(tmp)>255) break;
            //cout<<tmp<<endl;
            if(part>1) path += '.';
            path+=tmp;
            backTrack(s, i+1, part+1);
            path.resize(path.size()-tmp.size());
            if(part>1) path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backTrack(s, 0, 1);
        return res;
    }
};