# 28ms, 83.03%; 12.6MB, 100.00%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast = head
        while fast.next:
            fast = fast.next
            if fast.next: fast = fast.next
            head = head.next
        return head
