#include "data_structures/structures.hpp"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mpp;
        int res = 0;
        for(size_t i=0; i<nums1.size(); i++){
            for(size_t j=0; j<nums2.size(); j++){
                mpp[nums1[i]+nums2[j]]++;
            }
        }
        for(size_t i=0; i<nums3.size(); i++){
            for(size_t j=0; j<nums4.size(); j++){
                if(mpp.find(0-nums3[i]-nums4[j])!=mpp.end()){
                    res += mpp[0-nums3[i]-nums4[j]];
                }
            }
        }
        return res;
    }
};