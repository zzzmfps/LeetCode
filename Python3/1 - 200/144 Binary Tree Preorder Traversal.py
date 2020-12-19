# 48ms, 19.59%; 13.2MB, 6.12%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> list:
        res, stack = [], [root]
        while stack:
            node = stack.pop()
            while node:
                res.append(node.val)
                stack.append(node.right)
                node = node.left
        return res
