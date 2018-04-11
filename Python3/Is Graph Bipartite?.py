# 52ms, 95.96%
class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        size = len(graph)
        self.distro = [0] * size
        for i in range(size):
            if not self.distro[i] and not self.bipartite(graph, i, 1):
                return False
        return True

    def bipartite(self, graph, idx, type):
        if self.distro[idx]:
            return self.distro[idx] == type
        else:
            self.distro[idx] = type
        for g in graph[idx]:
            if not self.bipartite(graph, g, -type):
                return False
        return True
        
