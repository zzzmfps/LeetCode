# 44ms, 100.0%
class Solution:
    
    def binaryTreePaths(self, root):
        res = []
        if root: self.btp_helper(root, res, [str(root.val)])
        return res
    
    def btp_helper(self, root, res, st):
        if not root.left and not root.right:
            res.append(''.join(st))
        else:
            if root.left: self.btp_helper(root.left, res, st + ['->', str(root.left.val)])
            if root.right: self.btp_helper(root.right, res, st + ['->', str(root.right.val)])
        
