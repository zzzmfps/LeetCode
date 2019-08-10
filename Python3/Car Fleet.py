# 204ms, 83.72%; 16.4MB, 50.00%
class Solution:
    def carFleet(self, target: int, position: list, speed: list) -> int:
        tmp = sorted(zip(position, speed), reverse=1)
        time = [(target - x[0]) / x[1] for x in tmp]
        res, last = 0, 0
        for i in range(len(time)):
            if time[i] <= last:
                time[i] = last
            else:
                res += 1
                last = time[i]
        return res
