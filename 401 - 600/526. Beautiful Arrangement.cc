// 6ms, 98.92%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int countArrangement(int n) {
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        return counts(n, arr);
    }

private:
    int counts(int n, vector<int> &arr) {
        if (n == 0) return 1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i] % n == 0 || n % arr[i] == 0) {
                swap(arr[n - 1], arr[i]);
                ans += counts(n - 1, arr);
                swap(arr[n - 1], arr[i]);
            }
        return ans;
    }
};
