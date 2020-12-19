# 44ms, 61.50%; 13MB, 6.12%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head or not head.next: return head

        root = ListNode(0)
        root.next, ins = head, root
        while ins.next and ins.next.val < x:
            ins = ins.next
        pre, cur = ins, ins.next

        while cur:
            if cur.val < x:
                pre.next = cur.next
                cur.next = ins.next
                ins.next = cur
                ins, cur = ins.next, pre.next
            else:
                pre, cur = cur, cur.next
        return root.next
