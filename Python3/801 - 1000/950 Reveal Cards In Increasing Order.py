# 60ms, 33.12%; 14.1MB, 5.17%
class Solution:
    def deckRevealedIncreasing(self, deck: list) -> list:
        length = len(deck)
        orders, idx = [-1] * length, 0
        for i in range(length - 1):
            orders[idx] = i
            idx = self.__next(orders, idx)
        else:
            orders[self.__next(orders, idx, True)] = length - 1
        _sorted = sorted(deck)
        for i, v in enumerate(orders):
            orders[i] = _sorted[v]
        return orders

    def __next(self, arr, i, is_skipped=False):
        for j in range(i + 1, len(arr)):
            if arr[j] < 0:
                if is_skipped: return j
                is_skipped = True
        for j in range(1, i):
            if arr[j] < 0:
                if is_skipped: return j
                is_skipped = True
        return -1
        
