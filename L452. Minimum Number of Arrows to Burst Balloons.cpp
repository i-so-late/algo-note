#include "data_structures/structures.hpp"

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        int leftEdge = points[0][0];
        int rightEdge = points[0][1];
        for(int i=1; i< points.size(); ++i){
            if(points[i][0]>rightEdge){
                res++;
                leftEdge = points[i][0];
                rightEdge = points[i][1];
            }
            else{
                rightEdge = min(rightEdge, points[i][1]);
            }
        }
        return res;
    }
};