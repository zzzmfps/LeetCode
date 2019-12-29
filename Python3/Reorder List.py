# 84ms, 90.83%; 20.8MB, 100.00%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head: return
        slow, fast = head, head.next
        while fast:
            slow = slow.next
            fast = fast.next
            if fast: fast = fast.next
        link1, link2, slow.next = head, slow.next, None
        st = [node for node in self.__helper(link2)]
        while st:
            node = st.pop()
            link1.next, link1, node.next = node, link1.next, link1.next

    def __helper(self, head: ListNode) -> ListNode:
        while head:
            yield head
            head = head.next
