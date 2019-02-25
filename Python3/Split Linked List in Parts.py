# 48ms, 50.59%; 13.5MB, 6.45%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> list:
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        def getListLength(root: ListNode) -> int:
            ret = 0
            while root:
                root = root.next
                ret += 1
            return ret
        
        if not root: return [[] for _ in range(k)]

        list_len = getListLength(root)
        part_len = list_len // k
        left_num = list_len - k * part_len

        res, iter = [], root
        for i in range(min(k, list_len) - 1):
            res.append(iter)
            for _ in range(part_len - (0 if i < left_num else 1)):
                iter = iter.next
            iter.next, iter = None, iter.next
        res.append(iter)
        res += [[] for _ in range(max(0, k - list_len))]

        return res
