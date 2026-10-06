#include "data_structures/structures.hpp"

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int leftR = intervals[0][0];
        int rightR = intervals[0][1];
        vector<vector<int>> res;
        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0]>rightR){
                res.push_back({leftR, rightR});
                leftR = intervals[i][0];
                rightR = intervals[i][1];
            }else{
                rightR = max(rightR, intervals[i][1]);
            }
        }
        res.push_back({leftR, rightR});
        return res;
    }
};