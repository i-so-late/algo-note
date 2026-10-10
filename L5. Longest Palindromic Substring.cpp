#include "data_structures/structures.hpp"

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int ,int> idx{0, 0};
        int cur = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=s.size()-1; i>=0; --i){
            for(int j=i; j<s.size(); ++j){
                if(j-i<=1) dp[i][j] = s[i]==s[j]? j-i+1 : 0;
                else{
                    if(dp[i+1][j-1] == 0){
                        dp[i][j] = 0;
                    }else{
                        dp[i][j] = s[i] == s[j]? dp[i+1][j-1] + 2 : 0;
                    }
                }
                if(dp[i][j] > cur){
                    cur = dp[i][j];
                    idx = {i,j};
                }
            }
        }
        return s.substr(idx.first, idx.second - idx.first + 1);
    }
};