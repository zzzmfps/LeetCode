# 83ms, 76.01%
# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def __init__(self):
        self.__hash = {}
        
    def cloneGraph(self, node):
        if not node: return node
        if node not in self.__hash:
            self.__hash[node] = UndirectedGraphNode(node.label)
            for x in node.neighbors:
                (self.__hash[node].neighbors).append(self.cloneGraph(x))
        return self.__hash[node]
    
