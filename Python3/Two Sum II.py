# 40ms, 100.0%
class Solution:
    def twoSum(self, numbers, target):
        rem = {}
        for i in range(len(numbers)):
            if numbers[i] in rem: return [rem[numbers[i]] + 1, i + 1]
            rem[target - numbers[i]] = i
    
