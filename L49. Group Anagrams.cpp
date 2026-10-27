#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> um;
        vector<vector<string>> res;
        int idx = 0;
        for(int i=0; i<strs.size(); ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(um.count(tmp) == 0) {
                um[tmp] = idx++;
                res.push_back({strs[i]});
            }else{
                res[um[tmp]].push_back(strs[i]);
            }
        }
        return res;
    }
};