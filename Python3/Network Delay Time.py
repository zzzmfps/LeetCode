# 104ms, 97.70%
class Solution:
    def networkDelayTime(self, times, N, K):
        from collections import defaultdict
        nodes = defaultdict(dict)
        Q = set(range(N))
        for u, v, w in times:
            nodes[u - 1][v - 1] = w
        dist = [float('inf')] * N
        dist[K - 1] = 0
        while Q:
            u = None
            for node in Q:
                if u is None or dist[node] < dist[u]: u = node
            Q.remove(u)
            for v in nodes[u]:
                dist[v] = min(dist[v], dist[u] + nodes[u][v])
        d = max(dist)
        return -1 if d == float('inf') else d
    
