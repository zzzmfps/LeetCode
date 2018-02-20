# 52ms, 100.0%
class Solution:
    def deleteDuplicates(self, head):
        if not head or not head.next: return head
        trav_pre, trav_nxt = head, head.next
        while True:
            if trav_nxt.val == trav_pre.val:
                trav_nxt = trav_nxt.next
            else:
                trav_pre.next = trav_nxt
                trav_pre, trav_nxt = trav_nxt, trav_nxt.next
            if not trav_nxt:
                trav_pre.next = None
                return head
        
