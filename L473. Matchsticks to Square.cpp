#include "data_structures/structures.hpp"

class Solution {
public:
    int subSum = 0;
    bool backTrack(vector<int>& ms, vector<bool>& rec,int start, int k, int rest){
        if(k==1) return true;
        if(rest == 0) return backTrack(ms, rec, 0, k-1, subSum);
        for(int i=start; i<ms.size(); ++i){
            if(rec[i] || ms[i]>rest) continue;
            rec[i] = true;
            if(backTrack(ms, rec, start+1, k, rest-ms[i])) return true;
            rec[i] = false;

            if(rest == subSum) return false;
            while(i+1 < ms.size() && ms[i] == ms[i+1]) ++i;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i=0; i<matchsticks.size(); ++i){
            sum += matchsticks[i];
        }
        if(sum % 4) return false;
        subSum = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<bool> rec(matchsticks.size(), false);
        return backTrack(matchsticks, rec, 0, 4, subSum);
    }
};