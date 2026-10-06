#include "data_structures/structures.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> ss;
        for(auto p = headA; p != nullptr; p = p->next){
            ss.insert(p);
        }
        for(auto p = headB; p!= nullptr; p = p->next){
            if(ss.find(p)!=ss.end()) return p;
        }
        return nullptr;
    }
};