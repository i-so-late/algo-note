#include "data_structures/structures.hpp"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        unordered_set wd(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int j=1; j<=s.size(); ++j){
            for(int i=0; i<j; i++){
                string tmp = s.substr(i, j-i);
                if(wd.find(tmp) != wd.end() && dp[i]){
                    dp[j] = true;
                }
            }
        }
        return dp.back();
    }
};