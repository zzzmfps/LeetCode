# 140ms, 73.33%; 12.7MB, 100.0%
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.head = self.track = TreeNode(0)

    def increasingBST(self, root: 'TreeNode') -> 'TreeNode':
        if not root: return None
        self.increasingBST(root.left)
        self.track.right = TreeNode(root.val)
        self.track = self.track.right
        self.increasingBST(root.right)
        return self.head.right
        
