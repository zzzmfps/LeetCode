# 36ms, 99.82%
class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas) < sum(cost): return -1
        start, tmp = 0, 0
        for i in range(len(gas)):
            tmp += gas[i] - cost[i]
            if tmp < 0:
                start = i + 1
                tmp = 0
        return start
