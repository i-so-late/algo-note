#include "data_structures/structures.hpp"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int res = 0;
        stack<int> st;
        st.push(0);
        for(int i=1; i<heights.size(); ++i){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int mid = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                int l = right - left - 1;
                res = max(res, l * heights[mid]);
            }
            st.push(i);
        }
        return res;
    }
};