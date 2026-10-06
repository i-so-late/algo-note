#include "data_structures/structures.hpp"

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int pos = 0;
        int res = 0;
        int tmp = pos + nums[pos];
        while(true){
            if(tmp>=nums.size()-1) return ++res;
            int range = pos + nums[pos];
            for(int i=pos; i<=range && i<nums.size(); ++i){
                if(i+nums[i]>tmp) {
                    tmp = i+nums[i];
                    pos = i;       
                }
            }
            ++res;       
        }
        return res;
    }
};