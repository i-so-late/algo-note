#include "data_structures/structures.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int n = prices.size();
        vector<int> dp_min(n, prices[0]);
        vector<int> dp_max(n, prices[n-1]);
        for(int i=1; i<n; ++i){
            dp_min[i] = min(dp_min[i-1], prices[i]);
        }
        for(int j=n-2; j>=0; --j){
            dp_max[j] = max(dp_max[j+1], prices[j]);
        }
        int res = 0;
        for(int i=1; i<n; ++i){
            res = max(res, dp_max[i] - dp_min[i-1]);
        }
        return res;
    }
};