// 4ms, 63.79%; 8.8MB, 43.75%
class Solution
{
public:
    int numberOfArithmeticSlices(const vector<int> &A)
    {
        if (A.size() < 3) return 0;
        int diff = A[1] - A[0], count = 1, res = 0;
        for (int i = 2, size = A.size(); i < size; ++i) {
            int tmp = A[i] - A[i - 1];
            if (tmp == diff) {
                count += 1;
            } else {
                if (count > 1) res += count * (count - 1) >> 1;
                diff = tmp, count = 1;
            }
        }
        if (count > 1) res += count * (count - 1) >> 1;
        return res;
    }
};
