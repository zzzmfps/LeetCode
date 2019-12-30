# 40ms, 75.03%; 17.5MB, 88.89%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.ret = 0
        self.__helper(root)
        return self.ret

    def __helper(self, root: TreeNode) -> (int, int):
        if root.left is root.right: return (root.val, root.val)
        _min, _max = 100000, 0
        if root.left:
            _min, _max = self.__helper(root.left)
        if root.right:
            x, y = self.__helper(root.right)
            _min, _max = min(_min, x), max(_max, y)
        self.ret = max(self.ret, abs(root.val - _min), abs(root.val - _max))
        return (min(_min, root.val), max(_max, root.val))
