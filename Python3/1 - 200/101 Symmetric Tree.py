# 72ms, 46.55%
class Solution:
    
    def isSymmetric(self, root):
        if not root: return True
        return self.is_sym(root.left, root.right)
    
    def is_sym(self, l, r):
        if not l and not r: return True
        if l and r and l.val == r.val:
            return self.is_sym(l.left, r.right) and self.is_sym(l.right, r.left)
        return False
        
