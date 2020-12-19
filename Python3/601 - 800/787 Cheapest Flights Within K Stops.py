# 112ms, 28.56%; 13.6MB, 49.54%
class Solution:
    def findCheapestPrice(self, n: int, flights: list, src: int, dst: int, K: int) -> int:
        price = [2e4]*n
        price[src] = 0
        for _ in range(K + 1):
            tmp = price[:]
            for u, v, w in flights:
                tmp[v] = min(tmp[v], price[u] + w)
            price = tmp
        return price[dst] if price[dst] < 2e4 else - 1
