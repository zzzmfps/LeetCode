# 144ms, 82.04%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head: return None
        return self.toBST(head, None)

    def toBST(self, head, tail):
        if head == tail: return None
        fast = slow = head
        while fast is not tail and fast.next is not tail:
            fast = fast.next.next
            slow = slow.next
        ret = TreeNode(slow.val)
        ret.left = self.toBST(head, slow)
        ret.right = self.toBST(slow.next, tail)
        return ret
    
