# 44ms, 98.69%; 13.5MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        return self.__accumulate(root, 0)

    def __accumulate(self, root: TreeNode, acc: int) -> int:
        if not root: return 0
        acc = (acc << 1) | root.val
        if root.left is root.right: return acc
        return self.__accumulate(root.left, acc) + self.__accumulate(root.right, acc)
