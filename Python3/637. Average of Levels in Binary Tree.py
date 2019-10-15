# 60ms, 65.82%; 16.2MB, 7.14%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> list:
        res, st = [], [root]
        while st:
            res.append(0)
            tmp = []
            for node in st:
                res[-1] += node.val
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            res[-1] /= len(st)
            st = tmp
        return res
