# 136ms, 90.57%; 13.8MB, 12.50%
class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.prev = None
        self.next = None


class MyLinkedList:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head, self.tail = LinkedNode(-1), LinkedNode(-1)
        self.head.next, self.tail.prev = self.tail, self.head
        self.length = 0

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        node = self.__get_node_pointer(index)
        return node.val if node else -1

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list.
        After the insertion, the new node will be the first node of the linked list.
        """
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.addAtIndex(self.length, val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list.
        If index equals to the length of linked list, the node will be appended to the end of linked list.
        If index is greater than the length, the node will not be inserted.
        """
        shifted = self.tail if index == self.length else self.__get_node_pointer(index)
        if shifted is None: return
        previous = shifted.prev
        new_node = LinkedNode(val)  # will be inserted between `previous` and `replaced`
        new_node.prev, previous.next = previous, new_node
        new_node.next, shifted.prev = shifted, new_node
        self.length += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        deleted = self.__get_node_pointer(index)
        if deleted is None: return
        _prev, _next = deleted.prev, deleted.next
        _prev.next, _next.prev = _next, _prev
        self.length -= 1

    def __get_node_pointer(self, index: int) -> LinkedNode:
        '''
        Get the pointer to the index-th node. Excludes `self.head` and `self.tail`.
        '''
        node = None
        if index < 0 or index >= self.length: return node  # invalid
        if (index << 1) < self.length:  # near head
            node = self.head
            for _ in range(1 + index):  # 0-indexed
                node = node.next
        else:  # near tail
            node = self.tail
            for _ in range(self.length - index):
                node = node.prev
        return node


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
