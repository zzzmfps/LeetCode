# 68ms, 71.49%; 13.1MB, 5.71%
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip(' ')
        index = s.find('e')
        if index == -1:
            return self.__is_fraction(s)
        else:
            return self.__is_fraction(s[:index]) and self.__is_integer(s[index + 1:])

    def __is_integer(self, s: str, signal: bool = True, empty: bool = False) -> bool:
        if s.find(' ') != -1: return False
        if signal:
            length = len(s)
            s = s.lstrip('+-')
            if length - len(s) > 1: return False
        if not s: return empty
        return s.isdigit()

    def __is_fraction(self, s: str) -> bool:
        index = s.find('.')
        if index == -1:
            return self.__is_integer(s)
        elif index == 0:
            return self.__is_integer(s[1:], signal=False)
        elif index == len(s) - 1:
            return self.__is_integer(s[:-1])
        else:
            return self.__is_integer(s[:index], empty=True) and self.__is_integer(s[index + 1:], signal=False)
