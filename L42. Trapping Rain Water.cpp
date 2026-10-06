#include "data_structures/structures.hpp"

class Solution {
public:
    int trap(const vector<int>& height) {
        stack<int> st;
        int res = 0;
        for(size_t i=0; i<height.size(); ++i){
            while(!st.empty() && height[st.top()]<=height[i]){
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = min(height[st.top()], height[i]) - height[mid];\
                    int l = i-st.top()-1;
                    res += h*l;
                }
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    s.trap({0,1,0,2,1,0,1,3,2,1,2,1});
    return 0;
}