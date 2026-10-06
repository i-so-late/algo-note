#include "data_structures/structures.hpp"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> um;
        stack<int> st;
        for(int i=0; i<nums1.size(); ++i){
            um[nums1[i]] = i;
        }
        for(int i=0; i<nums2.size(); ++i){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                if(um.find(nums2[st.top()])!=um.end()){
                    int index = um[nums2[st.top()]];
                    res[index] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};