# 120ms, 100.0%
class Solution:
    def addTwoNumbers(self, l1, l2):
        is_carry = 0
        l3 = trav = ListNode(0)
        trap = trap.next = ListNode(0)    # order: left -> right
        while l1 is not l2:
            trav.next = trav = ListNode(0)
            tmp = l1.val + l2.val + is_carry
            is_carry = 1 if tmp > 9 else 0
            trav.val = tmp - 10 if is_carry else tmp
            l1 = l1.next if l1.next else trap
            l2 = l2.next if l2.next else trap
        if is_carry: trav.next = ListNode(1)
        return l3.next
    
