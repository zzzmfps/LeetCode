# 196ms, 96.90%; 16.2MB, 50.00%
class Solution:
    def carFleet(self, target: int, position: list, speed: list) -> int:
        tmp = sorted(zip(position, speed), reverse=1)
        res, last = 0, 0
        for i in range(len(tmp)):
            time = (target - tmp[i][0]) / tmp[i][1]
            if time > last:
                res += 1
                last = time
        return res
    
