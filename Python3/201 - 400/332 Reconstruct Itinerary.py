# 60ms, 78.67%; 13.5MB, 5.60%
from collections import defaultdict


class Solution:

    def findItinerary(self, tickets: list) -> list:
        self.map, self.res = defaultdict(list), []
        for t1, t2 in sorted(tickets)[::-1]:
            self.map[t1].append(t2)
        self.__visit('JFK')
        return self.res[::-1]

    def __visit(self, x: str) -> None:
        while self.map[x]:
            self.__visit(self.map[x].pop())
        self.res.append(x)
