#include "data_structures/structures.hpp"

class Solution {
public:
    string intToRoman(int num) {
        vector<char> rec = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        
        string res = "";
        int idx = -2;
        stack<int> st;
        while(num){
            int tmp = num%10;
            num /= 10;
            st.push(tmp);
            idx += 2;
        }
        while(!st.empty()){
            int tmp = st.top();
            st.pop();
            if(tmp==4){
                res += rec[idx];
                res += rec[idx+1];
            }
            else if(tmp < 4){
                for(int i=tmp; i>0; --i){
                    res += rec[idx];
                }
            }
            else if(tmp >= 5){
                int bit = tmp-5;
                if(bit == 4){
                    res += rec[idx];
                    res += rec[idx+2];
                    idx -=2;
                    continue;
                }
                res += rec[idx+1];
                for(int i=bit; i>0; --i){
                    res += rec[idx];
                }
            }
            idx -= 2;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.intToRoman(4)<<endl;
    return 0;
}