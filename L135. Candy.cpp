#include "data_structures/structures.hpp"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int base = 1;
        int res = 1;
        int decreaseLen = 1;
        int zenith = INT_MAX;
        for(int i=1; i<ratings.size(); ++i){
            if(ratings[i]<ratings[i-1]){
                base = 1;
                res += base;
                res += decreaseLen;
                decreaseLen++;
                if(decreaseLen >= zenith) res++;
            }else if(ratings[i]>ratings[i-1]){
                decreaseLen = 0;
                base++;
                res += base;
                zenith = base;
            }else{
                decreaseLen = 0;
                base = 1;
                res += base;
                zenith = base;
            }
        }
        return res;
    }
};