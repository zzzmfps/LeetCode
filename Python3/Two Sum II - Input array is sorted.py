# 40ms, 37.57%
class Solution(object):
    def twoSum(self, numbers, target):
        rem = dict()
        for i in range(len(numbers)):
            if numbers[i] in rem: return [rem[numbers[i]] + 1, i + 1]
            rem[target - numbers[i]] = i
    
