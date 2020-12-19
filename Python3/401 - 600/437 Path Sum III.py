# 752ms, 59.09%
class Solution:
    def pathSum(self, root, s):
        def find_path(root, s):
            if not root: return 0
            dif = s - root.val
            return (not dif) + find_path(root.left, dif) + find_path(root.right, dif)
        
        if not root: return 0
        return find_path(root, s) + self.pathSum(root.left, s) + self.pathSum(root.right, s)
    
