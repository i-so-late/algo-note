#include "data_structures/structures.hpp"

class Solution {
public:
    void reversePart(string& s, int left, int right){
        while(left<right){
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }

    string reverseStr(string s, int k) {
        int left = 0;
        int right = k-1;
        while(left<s.size()){
            //case 1: rest less than k
            if(right>=s.size()){
                right = s.size()-1;
                reversePart(s, left, right);
                return s;
            }
            reversePart(s, left, right);
            left += 2*k;
            right = left+k-1;
        }
        return s;
    }
};