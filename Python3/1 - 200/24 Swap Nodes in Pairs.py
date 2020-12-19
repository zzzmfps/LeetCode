# 40ms, 100.0%
class Solution:
    def swapPairs(self, head):
        if not head or not head.next: return head
        left, right = head, head.next
        pre = head = ListNode(0)
        while True:
            left.next = right.next
            right.next = left
            pre.next, pre = right, left
            if not left.next or not left.next.next: break
            left, right = left.next, left.next.next
        return head.next
    
