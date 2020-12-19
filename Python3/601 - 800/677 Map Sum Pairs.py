# 40ms, 45.48%; 13.2MB, 5.00%
class Node:
    def __init__(self, v: int):
        self.val = v
        self.next = dict()


class MapSum:
    def __init__(self):
        self.root = Node(0)


    def insert(self, key: str, val: int) -> None:
        trav = self.root
        flag, count = self.__helper(key)
        if flag:
            for k in key:
                trav.next[k].val -= count - val
                trav = trav.next[k]
        else:
            for k in key:
                if k in trav.next:
                    trav.next[k].val += val
                else:
                    trav.next[k] = Node(val)
                trav = trav.next[k]
            trav.next[0] = Node(0)


    def sum(self, prefix: str) -> int:
        return self.__helper(prefix)[1]


    def __helper(self, key: str) -> tuple:
        trav = self.root
        for k in key:
            if k in trav.next:
                trav = trav.next[k]
            else:
                return (False, 0)
        return (0 in trav.next, trav.val)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
