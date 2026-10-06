#include "data_structures/structures.hpp"

class Solution {
public:
    void reverseStr(string& s, int left, int right){
        while(left<right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        while(right<s.size() && s[right] == ' '){
            right++;
        }
        for(; right < s.size(); right++){
            if(right>0 && s[right] == s[right-1] && s[right]==' ') continue;
            else{
                s[left++] = s[right];
            }
        }
        if (left - 1 >0 && s[left-1] == ' '){
            s.resize(left-1);
        }else{
            s.resize(left);
        }

        reverseStr(s, 0, s.size()-1);
        left = 0;
        right = 0;

        while(left<s.size()){
            while(s[right]!=' ' && right != s.size()){
                right++;
            }
            reverseStr(s, left, right-1);
            left = right+1;
            right = left;
        }
        return s;
    }
};