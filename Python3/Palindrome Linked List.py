# 92ms, 100.0%
class Solution:
    def isPalindrome(self, head):
        rev = None
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast: slow = slow.next    # length is odd
        while rev and rev.val == slow.val:
            slow = slow.next
            rev = rev.next
        return not rev
'''
# 80ms, 100.0%
class Solution:
    def isPalindrome(self, head):
        a = []
        while head:
            a.append(head.val)
            head = head.next
        return a == a[:: -1]
'''
