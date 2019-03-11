# 96ms, 59.22%; 13MB, 6.67%
class Solution:
    def shoppingOffers(self, price: list, special: list, needs: list) -> int:
        for i in range(len(special) - 1, -1, -1):
            if not self.__list_ge(needs, special[i]) or special[i][-1] >= self.__list_mul(price, special[i]):
                special.pop(i)
        return self.__dfs(price, special, needs)

    def __dfs(self, price: list, special: list, needs: list) -> int:
        cost = self.__list_mul(price, needs)
        for sp in special:
            if self.__list_ge(needs, sp):
                self.__list_isub(needs, sp)
                cost = min(cost, sp[-1] + self.__dfs(price, special, needs))
                self.__list_iadd(needs, sp)
        return cost

    def __list_iadd(self, lhs:list, rhs: list):
        for i in range(len(lhs)):
            lhs[i] += rhs[i]

    def __list_isub(self, lhs:list, rhs: list):
        for i in range(len(lhs)):
            lhs[i] -= rhs[i]

    def __list_mul(self, lhs:list, rhs: list):
        ret = 0
        for i in range(len(lhs)):
            ret += lhs[i] * rhs[i]
        return ret

    def __list_ge(self, lhs:list, rhs: list):
        for i in range(len(lhs)):
            if lhs[i] < rhs[i]: return False
        return True
