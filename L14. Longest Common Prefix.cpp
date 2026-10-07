#include "data_structures/structures.hpp"

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        int idx = 0;
        while(idx < strs[0].size()){
            char c = strs[0][idx];
            for(int i=1; i<strs.size(); ++i){
                if(strs[i].size() <= idx || strs[i][idx]!=c)
                    return string(strs[0].begin(), strs[0].begin()+idx);
            }
            ++idx;
        }
        return strs[0].substr(0, idx);
    }
};

int main(){
    Solution s;
    cout<< s.longestCommonPrefix(vector<string>{"flower","flow","flight"})<<endl;
    return 0;
}