# 60ms, 100.0%
class Solution:
    def isBalanced(self, root):
        return self.check(root) != -1
    
    def check(self, root):                  # like the issue in Binary Tree Level Order Traversal II
            if root is None: return 0       # put this inside the function isBalanced will cost 72ms
            left = self.check(root.left)
            right = self.check(root.right)
            if left == -1 or right == -1 or abs(left - right) > 1:
                return -1
            return 1 + max(left, right)
        
