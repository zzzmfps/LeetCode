# 260ms, 60.40%; 15MB, 16.07%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        root = ListNode(0)
        root.next = head
        while True:
            while head.next and head.val <= head.next.val:
                head = head.next
            if not head.next: break
            ins = root
            while ins != head:
                if ins.next.val >= head.next.val: break
                ins = ins.next
            tmp = head.next
            head.next = tmp.next
            tmp.next = ins.next
            ins.next = tmp
        return root.next
