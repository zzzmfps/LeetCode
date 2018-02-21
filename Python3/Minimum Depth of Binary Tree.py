# 56ms, 100.0%
class Solution:
    def minDepth(self, root):
        if not root: return 0
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        return 1 + (min(left, right) if left and right else max(left, right))
        
