class MyLL:
    def __init__(self, val:int):
        self.val = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.root = MyLL(0)
        self.length = 0

    def get(self, index: int) -> int:
        if index >= self.length or index < 0:
            return -1
        t = self.root.next
        for i in range(index):
            t = t.next
        return t.val

    def addAtHead(self, val: int) -> None:
        tmp = MyLL(val)
        tmp.next = self.root.next
        self.root.next = tmp
        self.length += 1

    def addAtTail(self, val: int) -> None:
        p = self.root
        for i in range(self.length):
            p = p.next
        p.next = MyLL(val)
        self.length += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.length or index < 0:
            return 
        t = self.root
        for i in range(index):
            t = t.next
        p = MyLL(val)
        p.next = t.next
        t.next = p
        self.length += 1
    def deleteAtIndex(self, index: int) -> None:
        if index >= self.length or index < 0 :
            return
        p = self.root
        for i in range(index):
            p = p.next
        p.next = p.next.next
        self.length -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)