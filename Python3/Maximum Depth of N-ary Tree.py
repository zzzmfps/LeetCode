# 88ms, 60.29%; 17.4MB, 5.30%
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution:
    def maxDepth(self, root: Node) -> int:
        if not root: return 0
        stack, depth = [root], 0
        while stack:
            depth += 1
            tmp = []
            while stack:
                ptr = stack.pop()
                for p in ptr.children:
                    tmp.append(p)
            stack = tmp
        return depth
