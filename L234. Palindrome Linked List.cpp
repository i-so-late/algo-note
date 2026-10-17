#include "data_structures/structures.hpp"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> rec;
        while(head){
            rec.push_back(head->val);
            head = head->next;
        }
        for(int i=0, j=rec.size()-1; i<j; ++i, --j){
            if(rec[i]!=rec[j]) return false;
        }
        return true;
    }
};