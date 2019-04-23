# 40ms, 47.02%; 13.4MB, 7.25%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        self.prune(root)
        return None if root.val == 0 and root.left is root.right else root

    def prune(self, root: TreeNode):
        if root.left:
            if self.check(root.left):
                root.left = None
            else:
                self.prune(root.left)
        if root.right:
            if self.check(root.right):
                root.right = None
            else:
                self.prune(root.right)

    def check(self, root: TreeNode) -> bool:
        flag = (root.val == 0)
        if root.left:
            flag &= self.check(root.left)
        if root.right:
            flag &= self.check(root.right)
        return flag
