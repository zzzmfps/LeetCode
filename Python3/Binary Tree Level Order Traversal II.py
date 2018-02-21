# 40ms, 100.0%
class Solution:
    def levelOrderBottom(self, root):
        res = []
        self.dfs(root, 0, res)
        return res

    def dfs(self, root, level, res):    # much faster to put this function
        if root:                        # outside the function levelOrderBottom
            if len(res) < level + 1:    # def inside will cost 52~84ms
                res.insert(0, [])
            res[-(level + 1)].append(root.val)
            self.dfs(root.left, level + 1, res)
            self.dfs(root.right, level + 1, res)
