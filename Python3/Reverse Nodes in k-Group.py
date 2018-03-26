# 60ms, 96.07%
class Solution:
    def reverseKGroup(self, head, k):
        if(head is None or k == 1): return head
        num = 0
        dummy = ListNode(-1)
        dummy.next = head
        pre, cur, nxt = dummy, dummy, None
        while cur.next:
            num += 1
            cur = cur.next
        while num >= k:
            cur, nxt = pre.next, pre.next.next
            for i in range(1, k):
                pre.next, cur.next, nxt.next = nxt, nxt.next, pre.next
                nxt = cur.next
            pre = cur
            num -= k
        return dummy.next
    
