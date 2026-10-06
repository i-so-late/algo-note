#include "data_structures/structures.hpp"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        st.push(temperatures[0]);
        for(int i=1; i<temperatures.size(); ++i){
            while(temperatures[i]>st.top()){
                res[st.top()] = i-st.top();
                st.pop();
            }
            st.push(temperatures[i]);
        } 
        return res;       
    }
};