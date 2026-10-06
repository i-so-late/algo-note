#include "data_structures/structures.hpp"

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 1;
        int leftEdge = intervals[0][0];
        int rightEdge = intervals[0][1];
        for(int i=1; i< intervals.size(); ++i){
            if(intervals[i][0]>=rightEdge){
                res++;
                leftEdge = intervals[i][0];
                rightEdge = intervals[i][1];
            }
            else{
                rightEdge = min(rightEdge, intervals[i][1]);
            }
        }
        return intervals.size()-res;
    }
};