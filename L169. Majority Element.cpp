#include "data_structures/structures.hpp"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, cnt = 0;
        for(auto& i :nums){
            if(i != candidate && cnt == 0){
                candidate = i;
                ++cnt;
            }else if(i!=candidate){
                --cnt;
            }else{
                cnt++;
            }
        }
        return candidate;
    }
};