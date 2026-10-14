#include "data_structures/structures.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* cur = root;
        int carry = 0;
        int res = 0;
        while(l1!=nullptr && l2!=nullptr){
            cur->next = new ListNode();
            cur = cur->next;
            res = l1->val + l2->val;
            cur->val = (res+carry)%10;
            carry = (res+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            cur->next = l1;
        }
        else{
            cur->next = l2;
        }
        while(carry){
            if(!cur->next){
                cur->next = new ListNode(carry);
                break;
            }
            cur = cur->next;
            int res = cur->val;
            cur->val = (res + carry) % 10;
            carry = (res + carry) / 10;
        }
        return root->next;
    }
};