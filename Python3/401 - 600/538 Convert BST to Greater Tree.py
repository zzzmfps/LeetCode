# 92ms, 99.05%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """

        def visit(node):
            if node:
                visit(node.right)
                node.val += self.val
                self.val = node.val
                visit(node.left)

        self.val = 0
        visit(root)
        return root
    
