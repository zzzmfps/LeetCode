# 122ms, 47.99%
class Solution:
    def lowestCommonAncestor(self, root, p, q):    # iteration
        while root:
            p_cmp, q_cmp = root.val - p.val, root.val - q.val
            if p_cmp * q_cmp <= 0: return root
            elif p_cmp > 0:
                root = root.left
            else:
                root = root.right
        return None
'''
# 130ms, 30.65%
class Solution:
    def lowestCommonAncestor(self, root, p, q):    # recursion
        p_cmp, q_cmp = root.val - p.val, root.val - q.val
        if p_cmp * q_cmp <= 0: return root
        elif p_cmp > 0:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)
'''
