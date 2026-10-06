#include "data_structures/structures.hpp"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int tail = s.size() - 1;
        int head = 0;
        while(head < tail){
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
            head++;
            tail--;
        }
        return ;
    }
};