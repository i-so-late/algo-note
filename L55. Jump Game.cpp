#include "data_structures/structures.hpp"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        while(true){
            int tmp = pos + nums[pos];
            bool posChange = false;
            for(int i=pos; i<=pos + nums[pos]; ++i){
                if(i+nums[i]>=nums.size()-1) return true;
                if(i+nums[i]>tmp) {
                    tmp = i+nums[i];
                    pos = i;
                    posChange = true;
                }
            }
            if(!posChange) return false;
        }
        return false;
    }
};