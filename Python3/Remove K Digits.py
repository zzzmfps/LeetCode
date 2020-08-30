# 324ms, 19.62%; 13.9MB, 22.22%
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        num = list(num)
        for _ in range(k):
            for i in range(len(num) - 1):
                if num[i] > num[i + 1]:
                    num.pop(i)
                    break
            else:
                num.pop()
        res = ''.join(num).lstrip('0')
        return '0' if not res else res
