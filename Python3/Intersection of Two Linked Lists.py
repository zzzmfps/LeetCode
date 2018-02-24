# 314ms, 99.87%
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        trav_a, trav_b = headA, headB
        while trav_a is not trav_b:
            trav_a = headB if not trav_a else trav_a.next
            trav_b = headA if not trav_b else trav_b.next
        return trav_a
        
