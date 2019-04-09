# 48ms, 48.48%; 18.3MB, 5.28%
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head: return None
        p1, p2 = head, head
        while True:
            p1 = p1.next
            if not p1: return None
            p1 = p1.next
            if not p1: return None
            p2 = p2.next
            if p1 is p2: break

        cnt = 0
        while True:
            cnt += 1
            p1 = p1.next.next
            p2 = p2.next
            if p1 == p2: break

        p1, p2 = head, head
        for _ in range(1, cnt):
            p2 = p2.next
        while p1 is not p2.next:
            p1 = p1.next
            p2 = p2.next

        return p1
