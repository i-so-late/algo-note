#include "data_structures/structures.hpp"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* headB = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(headB));
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;
        while(a&&b){
            if(a->val < b->val){
                cur->next = a;
                a = a->next;
            }else{
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if(a) cur->next = a;
        else cur->next = b;
        return dummy.next;
    }
};