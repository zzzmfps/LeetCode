class Solution:
    def removeNthFromEnd(self, head, n):
        left = right = head
        for _ in range(n):
            right = right.next
        if right is None: return head.next
        while right.next:
            left = left.next
            right = right.next
        left.next = left.next.next
        return head
    
