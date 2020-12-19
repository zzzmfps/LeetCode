# 48ms, 96.89%
class Solution:
    def rotateRight(self, head, k):
        if head is None or head.next is None or not k: return head
        old_end, length = head, 1
        while old_end.next:
            length += 1
            old_end = old_end.next
        k %= length
        if not k: return head
        
        new_end = head
        for _ in range(length - k - 1):
            new_end = new_end.next
        head, new_end.next, old_end.next = new_end.next, None, head
        return head
        
