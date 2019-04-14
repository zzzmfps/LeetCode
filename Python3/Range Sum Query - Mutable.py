# 128ms, 70.36%; 16.7MB, 26.09%
class NumArray:
    def __init__(self, nums: list):
        size = len(nums)
        bucket_nums = int((size << 1)** 0.5)
        self.bucket_size = bucket_nums >> 1
        if bucket_nums * self.bucket_size < size: self.bucket_size += 1
        self.sums, i = [[[], 0] for _ in range(bucket_nums)], 0
        for j in range(bucket_nums):
            for _ in range(self.bucket_size):
                if i == size: break
                self.sums[j][0].append(nums[i])
                self.sums[j][1] += nums[i]
                i += 1

    def update(self, i: int, val: int) -> None:
        j, k = i // self.bucket_size, i % self.bucket_size
        self.sums[j][1] += val - self.sums[j][0][k]
        self.sums[j][0][k] = val

    def sumRange(self, i: int, j: int) -> int:
        i1, i2 = i // self.bucket_size, i % self.bucket_size
        j1, j2 = j // self.bucket_size, j % self.bucket_size
        res = 0
        for k in range(i1, j1 + 1):
            res += self.sums[k][1]
        res -= sum(self.sums[i1][0][:i2])
        res -= sum(self.sums[j1][0][j2 + 1:])
        return res

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
