# 212ms, 63.37%; 14MB, 5.10%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def constructMaximumBinaryTree(self, nums: list) -> TreeNode:
        if not nums: return None
        return self.build(nums, 0, len(nums))

    def build(self, nums: list, i: int, j: int) -> TreeNode:
        _max, _idx = nums[i], i
        for k in range(i + 1, j):
            if nums[k] > _max: _max, _idx = nums[k], k
        node = TreeNode(_max)
        if i < _idx: node.left = self.build(nums, i, _idx)
        if _idx + 1 < j: node.right = self.build(nums, _idx + 1, j)
        return node
