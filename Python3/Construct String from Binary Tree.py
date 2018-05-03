# 68ms, 92.27%
class Solution:
    def __init__(self):
        self.res = []

    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """

        def preorder(node):
            if not node: return
            self.res.append(str(node.val))
            if node.left or node.right:
                self.res.append('(')
                preorder(node.left)
                self.res.append(')')
            if node.right:
                self.res.append('(')
                preorder(node.right)
                self.res.append(')')

        preorder(t)
        return ''.join(self.res)
        

# 72ms, 63.64%
class Solution:
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t: return ''
        left = '({})'.format(self.tree2str(t.left)) if t.left or t.right else ''
        right = '({})'.format(self.tree2str(t.right)) if t.right else ''
        return '{}{}{}'.format(t.val, left, right)
    
