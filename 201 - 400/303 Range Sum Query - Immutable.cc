// 169ms, 64.54%  ----  WHY runs so slow compared to Python ?
class NumArray {
private:
    int *sums = nullptr;    // will cost 170ms if use vector
    
public:
    NumArray(vector<int> nums) {
        int end = nums.size();
        sums = new int [end + 1];
        sums[0] = 0;
        for (int i = 0; i < end; ++i)
            sums[i + 1] = sums[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};
