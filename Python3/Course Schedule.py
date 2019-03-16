# 236ms, 21.37%; 14MB, 63.39%
class Solution:
    def canFinish(self, numCourses: int, prerequisites: list) -> bool:
        res = [len(prerequisites)]
        cnt = [0] * numCourses  # in-degree
        pre = [[] for _ in range(numCourses)]   # adjacency matrices
        for p in prerequisites:
            cnt[p[0]] += 1
            pre[p[1]].append(p[0])
        while self.__delete(pre, cnt, res):
            pass
        return res[0] == 0
        
    def __delete(self, pre: set, cnt: list, res: list) -> int:
        for i, x in enumerate(cnt):
            if x == 0: break
        else:
            return 0
        cnt[i] = -1
        for node in pre[i]:
            cnt[node] -= 1
            res[0] -= 1
        return True
