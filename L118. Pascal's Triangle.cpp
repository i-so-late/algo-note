#include "data_structures/structures.hpp"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1; i<numRows; ++i){
            int len = i+1;
            vector<int> path(len, 0);
            int mid = (len+1)/2;
            path[0] = 1;
            for(int j=1; j<mid; ++j){
                path[j] = res[i-1][j-1] + res[i-1][j];
            }
            for(int j=mid; j<len; ++j){
                path[j] = path[len-1-j];
            }
            res.push_back(path);
        }
        return res;
    }
};