# 40ms, 100.0%
class Solution:
    def invertTree(self, root):
        if not root: return None
        root.left = self.invertTree(root.left)
        root.right = self.invertTree(root.right)
        root.left, root.right = root.right, root.left
        return root
        
