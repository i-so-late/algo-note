#include "data_structures/structures.hpp"

class Solution {
public:
    long long appealSum(string s) {
        vector<int> dp(s.size()+1, 0);
        vector<int> last(26, -1);
        long long res = 0;
        for(int i=0; i<s.size(); ++i){
            dp[i+1] = dp[i] + i - last[s[i]-'a'];
            last[s[i]-'a'] = i;
            res += dp[i+1];
        }
        return res;
    }
};