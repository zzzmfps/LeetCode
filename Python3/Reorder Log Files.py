# 44ms, 73.21%; 13.1MB, 6.17%
class Solution:
    def reorderLogFiles(self, logs: list) -> list:
        letter = [logs.pop(i) for i, x in list(enumerate(logs))[::-1] if x[-1].isalpha()]
        letter.sort(key=lambda x: x.partition(' ')[::-1])
        return letter + logs
