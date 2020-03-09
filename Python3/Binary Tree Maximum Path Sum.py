# 88ms, 77.34%; 19.5MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.max = float('-inf')
        self.helper(root)
        return self.max

    def helper(self, root: TreeNode) -> int:
        if not root: return 0
        left, right = self.helper(root.left), self.helper(root.right)
        _sum = root.val + max(0, left) + max(0, right)
        self.max = max(self.max, _sum)
        return root.val + max(0, left, right)
