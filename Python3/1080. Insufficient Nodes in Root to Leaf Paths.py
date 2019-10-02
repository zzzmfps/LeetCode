# 88ms, 99.40%; 15.4MB, 100.00%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        tmp = TreeNode(0)
        tmp.left = root
        self.helper(tmp, limit, 0)
        return tmp.left

    def helper(self, node: TreeNode, limit: int, val: int) -> bool:
        if not node: return False
        val += node.val
        if node.left or node.right:
            flag1 = self.helper(node.left, limit, val)
            flag2 = self.helper(node.right, limit, val)
            if not flag1: node.left = None
            if not flag2: node.right = None
            return flag1 or flag2
        else:
            return limit <= val
