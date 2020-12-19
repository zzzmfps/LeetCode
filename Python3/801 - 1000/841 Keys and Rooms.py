# 68ms, 5.69%; 14.2MB, 9.66%
class Solution:
    def canVisitAllRooms(self, rooms: list) -> bool:
        count, nums = 1, len(rooms)
        _next, _arr = [0], [True] * nums
        _arr[0] = False
        
        while _next:
            idx = _next.pop(-1)
            for key in rooms[idx]:
                if _arr[key]:
                    _next.append(key)
                    _arr[key] = False
                    count += 1
            if count == nums: return True
        return False
