# 48ms, 83.13%; 14.6MB, 100.00%
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def preorder(self, root: Node) -> List[int]:
        if not root: return []
        q, res = [root], []
        while q:
            tmp = q.pop()
            res.append(tmp.val)
            for child in tmp.children[::-1]:
                q.append(child)
        return res
