# 44ms, 66.37%; 13.7MB, 10.32%
class Solution:
    def findKthLargest(self, nums: list, k: int) -> int:
        _min, _max, length = nums[0], nums[0], len(nums)
        for n in nums:
            if n < _min: _min = n
            elif n > _max: _max = n
        if k == 1: return _max
        if k == length: return _min
        while _min < _max:
            _mid = (_min + _max) // 2
            le, lt = 0, 0
            for n in nums:
                if n >= _mid:
                    le += 1
                    if n > _mid: lt += 1
            if lt < k and le >= k:
                return _mid
            if lt >= k:
                _min = _mid + 1
            else:
                _max = _mid - 1
        return _min
