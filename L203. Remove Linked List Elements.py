# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode | None, val: int) -> ListNode | None:
        root = ListNode()
        root.next = head
        t = root
        while t.next:
            if t.next.val == val:
                t.next = t.next.next
            else:
                t = t.next
        return root.next

        