#include "data_structures/structures.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode(0, head);
        ListNode* cur =  head;
        ListNode* prev = root;
        for(int i=0; i< n; ++i){
            cur = cur->next;
        }
        while(cur){
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = prev->next ? prev->next->next : nullptr;
        return root->next;
    }
};