# 60ms, 80.00%; 12.7MB, 100.00%
from typing import List, Tuple


class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1, arr2 = self.__helper(arr1, arr2)
        i, carry1, carry2 = len(arr1) - 1, 0, 0
        while i > -1:
            arr1[i] += arr2[i] + carry2
            if arr1[i] == 4:
                arr1[i], carry1, carry2 = 0, 1, carry1
            elif arr1[i] >= 2:
                arr1[i], carry1, carry2 = arr1[i] - 2, 1, 1 + carry1
            else:
                carry1, carry2 = 0, carry1
            i -= 1
        if (carry1, carry2) != (1, 2): arr1 = [carry1, carry2] + arr1
        try:
            return arr1[arr1.index(1):]
        except Exception:
            return [0]

    def __helper(self, arr1: List[int], arr2: List[int]) -> Tuple[List[int], List[int]]:
        diff = len(arr1) - len(arr2)
        if diff > 0:
            arr2 = [0] * diff + arr2
        elif diff < 0:
            arr1 = [0] * (-diff) + arr1
        return arr1, arr2

