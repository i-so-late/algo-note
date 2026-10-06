#include "data_structures/structures.hpp"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool rec1[1001] = {false};
        bool rec2[1001] = {false};
        for(int i=0; i< nums1.size(); i++){
            rec1[nums1[i]] = true;
        }
        for(int i=0; i<nums2.size(); i++){
            rec2[nums2[i]] = true;
        }
        vector<int> res;
        for(int i=0; i<1001; i++){
            if(rec1[i]&rec2[i]) res.push_back(i);
        }
        return res;
    }
};