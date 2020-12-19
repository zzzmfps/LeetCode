static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// 0, exhaustion method: 4ms, 99.83%; 8.2MB, 29.03%
class Solution
{
private:
    int arr[9] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};

public:
    int countNumbersWithUniqueDigits(int n) { return arr[n]; }
};

// 1, normal: 4ms, 99.83%; 8.3MB, 12.90%
class Solution
{
private:
    int choices[10] = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1};

public:
    int countNumbersWithUniqueDigits(int n)
    {
        int res = 1, product = 1, end = min(n, 10);
        for (int i = 0; i < end; ++i) {
            product *= choices[i];
            res += product;
        }
        return res;
    }
};
