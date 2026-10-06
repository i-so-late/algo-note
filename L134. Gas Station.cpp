#include "data_structures/structures.hpp"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0;
        int curSum = 0;
        int startPos = 0;
        int n = gas.size();
        int i=0;

        int g = 0; int c = 0;
        for(int i=0; i<gas.size(); i++){
            g += gas[i];
            c += cost[i];
        }
        if(g<c) return -1;

        while(true){
            rest = gas[i] - cost[i];
            curSum += rest;
            if(curSum<0){
                i = (i+1) % n;
                curSum = 0;
                rest = 0;
                startPos = i;
                continue;
            }
            i = (i+1) % n;
            if(i == startPos) return i;
        }
        return -1;
    }
};