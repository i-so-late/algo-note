#include "data_structures/structures.hpp"

class Solution {
public:
    int _getSum(int n){
        int sum = 0;
        while(n){
            int tmp = n%10;
            sum += tmp*tmp;
            n /= 10;
        }   
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            n = _getSum(n);
            if(n==1) return true;
            if(st.find(n)!=st.end()) break;
            else st.insert(n);
        }
        return false;
    }
};