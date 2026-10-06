#include "data_structures/structures.hpp"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); ++i){
            if(tokens[i] == "+"){
                int num1 = st.top();
                st.pop();
                int nums2 = st.top();
                st.pop();
                st.push(num1+nums2);
            }else if(tokens[i] == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2-num1);
            }else if(tokens[i] == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);
            }else if(tokens[i] == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};