#include "data_structures/structures.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size(), 0);
        int res = 0;
        for(int i=1; i<s.size(); ++i){
            if(s[i] == '(') continue;
            
            int j = i-dp[i-1]-1;
            if(j<0 || s[j] == ')') continue;
            dp[i] = dp[i-1] + 2;
            if(j>1) dp[i] += dp[j-1];
            res = max(dp[i], res);
        }
        return res;
    }
};