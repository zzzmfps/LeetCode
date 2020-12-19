# 52ms, 100.0%
class Solution:
    def hasPathSum(self, root, sum):
        if not root: return False
        if root.val == sum and not root.left and not root.right:
            return True
        sum -= root.val
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
        
