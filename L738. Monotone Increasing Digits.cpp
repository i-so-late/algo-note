#include "data_structures/structures.hpp"

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int numofDigits = 0;
        stack<int> st;
        while(n){
            int rest = n%10;
            n /= 10;
            if(st.empty() || st.top()>=rest) st.push(rest);
            else{
                numofDigits = 0;
                while(!st.empty()){
                    st.pop(); numofDigits++;
                }
                while(numofDigits--){
                    st.push(9);
                }
                st.push(rest-1);
            }
        }
        int res=0; 
        while(!st.empty()){
            res = res*10 + st.top();
            st.pop();
        }        
        return res;
    }
};