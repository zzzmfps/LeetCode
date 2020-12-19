# 48ms, 100.0%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def depthOfBinaryTree(root, ret):
            if not root: return 0
            left = depthOfBinaryTree(root.left, ret)
            right = depthOfBinaryTree(root.right, ret)
            ret[0] = max(ret[0], left + right)
            return 1 + max(left, right)

        ret = [0]
        depthOfBinaryTree(root, ret)
        return ret[0]
