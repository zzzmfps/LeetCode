# 56ms, 95.53%; 14.3MB, 100.00%
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        st = [root]
        while True:
            if st[0].left is None: break
            _new = []
            while st:
                node = st.pop(0)
                _new.extend([node.left, node.right])
            for i in range(1, len(_new)):
                _new[i - 1].next = _new[i]
            st = _new
        return root
