# 140ms, 74.38%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        stack, ret = [root], 0
        while stack:
            tmp = stack.pop()
            ret += 1
            if tmp.left:
                stack.append(tmp.left)
                if tmp.right: stack.append(tmp.right)
        return ret
