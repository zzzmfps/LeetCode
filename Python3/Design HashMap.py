# 136ms, 64.60%; 16.1MB, 41.38%
class MyHashMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.my_hash_map = [[] for _ in range(101)]

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        i, j, k = self.__get_index(key)
        if not self.my_hash_map[i]: self.my_hash_map[i] = [[] for _ in range(100)]
        if not self.my_hash_map[i][j]: self.my_hash_map[i][j] = [0] + [-1] * 100
        if self.my_hash_map[i][j][k] < 0: self.my_hash_map[i][j][0] += 1
        self.my_hash_map[i][j][k] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        i, j, k = self.__get_index(key)
        if not self.my_hash_map[i] or not self.my_hash_map[i][j]: return - 1
        return self.my_hash_map[i][j][k]

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        i, j, k = self.__get_index(key)
        if self.my_hash_map[i] and self.my_hash_map[i][j] and self.my_hash_map[i][j][k] >= 0:
            if self.my_hash_map[i][j][0] == 1:
                self.my_hash_map[i][j].clear()
            else:
                self.my_hash_map[i][j][0] -= 1
                self.my_hash_map[i][j][k] = -1

    def __get_index(self, key) -> (int, int, int):
        """
        Returns the index of value that stored or to be stored
        """
        return (key // 10000, key // 100 % 100, key % 100 + 1)

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
