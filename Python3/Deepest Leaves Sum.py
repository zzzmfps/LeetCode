# 96ms, 67.23%; 16.4MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        _sum, q = 0, deque([root])
        while q:
            _sum = 0
            for _ in range(len(q)):
                tmp = q.popleft()
                _sum += tmp.val
                if tmp.left: q.append(tmp.left)
                if tmp.right: q.append(tmp.right)
        return _sum
