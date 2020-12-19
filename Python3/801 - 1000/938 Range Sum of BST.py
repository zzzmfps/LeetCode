# 228ms, 64.67%; 20.9MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        self.sum = 0
        self.__helper(root, L, R)
        return self.sum

    def __helper(self, node: TreeNode, L: int, R: int) -> int:
        if not node or L > R: return
        if L <= node.val <= R: self.sum += node.val
        if node.val > L: self.__helper(node.left, L, min(R, node.val - 1))
        if node.val < R: self.__helper(node.right, max(L, node.val + 1), R)
