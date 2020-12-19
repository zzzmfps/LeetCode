# 88ms, 100.0%
class Solution:
    def removeElements(self, head, val):
        while head:
            if head.val == val:
                head = head.next
            else:
                break
        else: return None
        trav = head
        while trav.next:
            if trav.next.val == val:
                trav.next = trav.next.next
            else:
                trav = trav.next
        return head
    
