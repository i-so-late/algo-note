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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* p = head->next;
        ListNode* t = head;
        while(p != nullptr) {
            ListNode* tmp = p->next;           
            p->next = t;
            t = p;
            p = tmp;
        }
        head->next = nullptr;
        return t;
    }
};