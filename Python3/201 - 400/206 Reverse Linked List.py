# 52ms, 99.75%
class Solution:
    def reverseList(self, head):
        if head and head.next:
            last, trav = head, head.next
            while trav:
                last.next, trav.next, head = trav.next, head, trav
                trav = last.next
        return head
    
