#include "data_structures/structures.hpp"

class Solution {
public:
    ListNode* recursiveSwap(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* tmp = head->next->next;
        ListNode* ret = head->next;
        head->next->next = head;
        head->next = recursiveSwap(tmp);
        return ret;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* root = new ListNode();
        root->next = head->next;
        recursiveSwap(head);
        return root->next;
    }
};