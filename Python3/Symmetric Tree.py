# 72ms, 46.55%
class Solution:
    def isSymmetric(self, root):
        if not root: return True
        return self.helper(root.left, root.right)
    
    def helper(self, l, r):
        if not l and not r: return True
        if l and r and l.val == r.val:
            return self.helper(l.left, r.right) and self.helper(l.right, r.left)
        return False
        
