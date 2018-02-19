# 44ms, 100.0%
class Solution:
    def mergeTwoLists(self, l1, l2):
        if not l1: return l2
        if not l2: return l1
        if l1.val > l2.val: l1, l2 = l2, l1
            
        head, tmp = l1, l2
        while l1.next and l2:
            if l1.next.val <= l2.val:
                l1 = l1.next
            else:
                l2 = l2.next
                tmp.next = l1.next
                l1.next = tmp
                l1 = l1.next
                tmp = l2
        if not l1.next: l1.next = l2
        return head
        
