# 32ms, 97.11%; 12.6MB, 100.00%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None: return head
        root = ListNode(0)
        root.next, cur = head, root
        while cur.next:
            nxt = cur.next
            while nxt.next and nxt.next.val == cur.next.val:
                nxt = nxt.next
            if cur.next == nxt:
                cur = nxt
            else:
                cur.next = nxt.next
        return root.next
