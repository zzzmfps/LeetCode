# 316ms, 86.28%; 13.2MB, 100.00%
from typing import List, Tuple


class Solution:  # quite similar with #797
    def exist(self, board: List[List[str]], word: str) -> bool:
        start = self.__find(board, word[0])
        if not start: return False  # first char not exists or board is empty
        row, col = len(board), len(board[0])
        st, visited = [start], [[False] * col for _ in range(row)]
        while st:
            if len(st) == len(word): return True  # completed the word
            i, j = st[-1][-1]  # add this one into 'stack'
            visited[i][j] = True
            next_step = self.__find(board, word[len(st)], st[-1][-1], visited)
            if next_step:  # (i, j) is correct so far
                st.append(next_step)
            else:  # cannot continue, then rollback the stack and visit status
                while st and len(st[-1]) == 1:
                    x, y = st.pop()[0]
                    visited[x][y] = False
                if st:
                    x, y = st[-1].pop()
                    visited[x][y] = False
        return False

    def __find(self,
               board: List[List[str]],
               char: str,
               hint: Tuple[int] = None,
               visited: List[List[bool]] = None) -> List[Tuple[int]]:
        ret = []
        if hint:  # check at most four adjacent cells
            i, j = hint
            if i and board[i - 1][j] == char and not visited[i - 1][j]: ret.append((i - 1, j))
            if j and board[i][j - 1] == char and not visited[i][j - 1]: ret.append((i, j - 1))
            if i + 1 < len(board) and board[i + 1][j] == char and not visited[i + 1][j]: ret.append((i + 1, j))
            if j + 1 < len(board[0]) and board[i][j + 1] == char and not visited[i][j + 1]: ret.append((i, j + 1))
        else:  # find start points
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if board[i][j] == char: ret.append((i, j))
        return ret
